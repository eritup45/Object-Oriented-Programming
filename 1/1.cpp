#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX_NODES 500
#define START -1
#define NOT -2
#define NNN 10000000000
#define NN 100000
using namespace std;
struct recorded
{
    int from;
    double cost;
};
struct way
{
    int to, capacity, load;
};
void init(int &ln_node, int &ln_road);
double cal(int load, int capacity);
void build_table(int &ln_node, int the_num);
void occupy(int ln_node, int node_a, int node_b, int cost);
void out(stack<int> &output);
void print();

vector<struct way> node[MAX_NODES];
queue<int> ans;
int ans_cost, ans_lnnode;

int main()
{
    int ln_node, ln_road, test, the_num = 0;
    ans_cost = 0, ans_lnnode = 0;
    init(ln_node, ln_road);

    scanf("%d", &test);
    while (test--)
        build_table(ln_node, the_num++);

    printf("%d %d\n", ans_lnnode, ans_cost);
    print();
    return 0;
}

void init(int &ln_node, int &ln_road)
{
    int i, a, b, c, d;
    struct way trans;
    freopen("a.txt", "r", stdin);
    scanf("%d%d", &ln_node, &ln_road);
    for (i = 0; i < ln_road; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        trans.capacity = d;
        trans.load = 0;
        trans.to = c;
        node[b].push_back(trans); //¦s¤Jvector
        trans.to = b;
        node[c].push_back(trans);
    }
}

void build_table(int &ln_node, int the_num)
{
    int times, startP, endP, cost;
    int i, now;
    double to;
    struct recorded table[MAX_NODES];
    queue<int> flow;
    stack<int> output;

    scanf("%d%d%d%d", &times, &startP, &endP, &cost);

    //init
    for (i = 0; i < ln_node; i++)
    {
        table[i].from = NOT;
        table[i].cost = NNN;
    }
    table[startP].from = START; //-1
    table[startP].cost = 0;


    flow.push(startP);
    while (flow.size() != 0)
    {
        now = flow.front();
        flow.pop();

        for (i = 0; i < node[now].size(); i++)
        {
            to = cal(node[now][i].load, node[now][i].capacity);
            if ((table[node[now][i].to].cost > table[now].cost + to)\
                 && (cost + node[now][i].load <= node[now][i].capacity))
            {
                table[node[now][i].to].cost = table[now].cost + to;
                table[node[now][i].to].from = now;
                if (node[now][i].to != endP)
                    flow.push(node[now][i].to);
            }
        }
    }

    now = endP;
    if (table[endP].from != NOT)
    {
        output.push(now);
        while (table[now].from != -1)
        {
            occupy(ln_node, now, table[now].from, cost);
            now = table[now].from;
            output.push(now);
        }
        output.push(the_num);
        out(output);
        ans_lnnode++;
        ans_cost += cost;
    }
}


double cal(int load, int capacity)
{
    if ((double)load / (double)(capacity - load) > NN)
        return NN;
    else
        return (double)load / (double)(capacity - load);
}


void occupy(int ln_node, int node_a, int node_b, int cost)
{
    int i;
    for (i = 0; i < node[node_a].size(); i++)
        if (node[node_a][i].to == node_b)
            node[node_a][i].load += cost;
    for (i = 0; i < node[node_b].size(); i++)
        if (node[node_b][i].to == node_a)
            node[node_b][i].load += cost;
}


void out(stack<int> &output)
{
    while (!output.empty())
    {
        ans.push(output.top());
        output.pop();
    }
    ans.push(-1);
}


void print()
{
    while (!ans.empty())
    {
        if (ans.front() != -1)
            printf("%d ", ans.front());
        else
            printf("\n");
        ans.pop();
    }
}
