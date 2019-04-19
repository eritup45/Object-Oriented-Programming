#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<cfloat>
using namespace std;
#define INF 1000000000
#define MAX_NODES 1024
#define START_POSITION -1
#define EOL -100
typedef struct graph{
    int to;         // Capable to reach sth.
    int capacity;   // Store from [i] to [j]'s "capacity"
    int load;       // If succeed, store the "load"
}graph;

typedef struct table{
    int parent;    // Store the [i]'s "parent"
    double cost;   // Store the "cost" from source to [i]
}table;

vector<graph> g[MAX_NODES];  // For g[i], "i" is from. g[i][0].to, g[i][1].to is the next node.
table t[MAX_NODES];

int acceptedFlows = 0, totalThroughPut = 0; // Used to output result
queue<int> ans;

void init(int *totalNode, int *totalInput){ //initialize g
    int i;
    int tmp, from, to, cap;
    graph trans;
    scanf("%d %d", totalNode, totalInput);
    for(i = 0; i < *totalInput; i++){    // Read data
        scanf("%d %d %d %d", &tmp, &from, &to, &cap);
        trans.to = to;
        trans.capacity = cap;
        trans.load = 0;
        g[from].push_back(trans);
        trans.to = from;    // Undirected graph
        g[to].push_back(trans);
    }
}

double get_cost(int load, int capacity){
    if(load == capacity)    return 2 * INF;
    else    return (double)load/(double)(capacity-load);
}

void occupy (int from,int to,int load){ // update two-way's load
    int i;
    for (i=0; i<g[from].size(); i++)
        if (g[from][i].to == to)        g[from][i].load += load;
    for (i=0; i<g[to].size(); i++)
        if (g[to][i].to == from)        g[to][i].load += load;
}

void update_load(int endp, int load){
     stack<int> s;
    int from, to, i = endp;
    if(t[endp].parent == START_POSITION)
        return;
    acceptedFlows++;    totalThroughPut += load;
    s.push(endp);
    while(t[i].parent != START_POSITION){
        s.push(t[i].parent);
        i = t[i].parent;
    }
    while(s.size() != 1){
        from = t[s.top()].parent;
        to = s.top();
        occupy(from, to, load);
        s.pop();
    }
}

void bfs_get_table(int startp, int endp, int load){   // Get table by BFS
    queue<int> q;
    int from, to;
    double cost;
    q.push(startp);
    while(q.size() != 0){
        from = q.front();
        q.pop();
        for(int i = 0; i < g[from].size(); i++){ // i �Og[from]���ĴX��, PS. from �� g[from][i].to
            cost = get_cost(g[from][i].load, g[from][i].capacity);
            to = g[from][i].to;
            // 1. Consider whether the next node should add. 2. (cost + load) can't exceed capacity
            if( (cost + t[from].cost < t[to].cost) &&\
                    (load + g[from][i].load <= g[from][i].capacity) ){  //printf ("%d = %d !! %lf = %lf = %lf\n",from, to, t[from].cost, t[to].cost, cost);
                t[to].cost = cost + t[from].cost;
                t[to].parent = from;
                if(to != endp){
                    q.push(to);
                }
            }
        }
    }
    update_load(endp, load);
}

void add_ans(int endp, int n){
    stack<int> s;
    if(t[endp].parent == START_POSITION)
        return;
    ans.push(n);
    s.push(endp);
    int i = endp;
    while(t[i].parent != START_POSITION){
        s.push(t[i].parent);
        i = t[i].parent;
    }
    while(s.size() != 0){
        //printf("%d ", s.top());
        ans.push(s.top());
        s.pop();
    }
    ans.push(EOL);
    //printf("\n");
}

void print_ans(){
    printf("%d %d\n", acceptedFlows, totalThroughPut);
    while(ans.size() != 0){
        if(ans.front() == EOL){
            printf("\n");
            ans.pop();
            continue;
        }
        printf("%d ",ans.front());
        ans.pop();
    }
}

int main(){
    int totalNode, totalInput;
    int i=0, j=0;
    freopen("./TESTING_DATA/request5OK.txt", "r", stdin);
    //freopen("my_ans.txt", "w", stdout);
    init(&totalNode, &totalInput);

    int totalLoad;
    int n, startp, endp, load;
    scanf("%d", &totalLoad);
    for(i = 0; i < totalLoad; i++){

        for(j = 0; j < totalNode; j++){ // initialize t
            t[j].parent = -1;   // no parent
            t[j].cost = DBL_MIN;    // very small floating-number
        }
        scanf("%d %d %d %d", &n, &startp, &endp, &load);
        t[startp].parent = START_POSITION;
        t[startp].cost = (-1) * INF;

        bfs_get_table(startp, endp, load); // *** get table ***
        add_ans(endp, n);
    }

    print_ans();
    return 0;
}
