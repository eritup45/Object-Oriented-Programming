#include <iostream>
#include <random>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10000

//#include<bits/stdc++.h>

void online_bipartite_matching();

int rd;
default_random_engine gen;
uniform_real_distribution<double> unif(0, 1);

class Request{  
    int id;  
    bool matched = 0; 
    int resourceId = -1;
    double weight; // a random value, indicates the priority
public: 
    friend class Resource;
    Request(int _id, double _weight) : id(_id), weight(_weight) {}   // constructor updates id
    // accessor
    int getID(){
        return id;
    }
    double getWeight(){
        return weight;
    }
    bool getmatched(){
        return matched;
    }
    int get_resourceId(){
        return resourceId;
    }
};

class Resource{  
    int id;  
    bool matched = 0; 
    int requestId = -1;
public:
    static int count;
    Resource(int _id) : id(_id) {}
    const bool operator ->* (Request &b){    // ->* check whether both of them are un-matched.  
        if(b.matched || matched){
            return false;
        }
        matched = b.matched = 1;
    	requestId = b.id;
    	b.resourceId = id;
        return true;
    }
    // accessor
    bool getmatched(){
        return matched;
    }
    int get_requestId(){    // d
        return requestId;
    }
    int getID() {
  		return id;
  	}
};
int Resource::count = 0;    // Used to count the result

typedef struct Edge{
    int id, from, to;
    double w;
}Edge;

struct cmp{ // Used in priority_queue
    bool operator ()(Edge a, Edge b){
        if(a.w == b.w)  return a.from > b.from;
        return a.w < b.w;
    }
};

vector<Request> request;
vector<Resource> resource;
priority_queue<Edge, vector<Edge>, cmp> graph[MAX];

int main(int argc, char** argv){
    rd = atoi(argv[1]);
    gen.seed(rd);
    freopen("./test_file/request3.txt", "r", stdin);
    freopen("MYRESULT.txt", "w", stdout);
    int nTimeSlots;
    cin >> nTimeSlots;
    while(nTimeSlots--)
        online_bipartite_matching();
    cout << Resource::count << "\n";
    for(int i=0; i < request.size(); i++){
        if(request[i].getmatched())
            cout << request[i].getID() << " " << request[i].get_resourceId() << "\n";
    }
    return 0;
}

void online_bipartite_matching(){
    int timeSlotID, nrequests, nresources, nedges;
    cin >> timeSlotID >> nrequests >> nresources;
    for(int i = 0; i < nrequests; i++){
        int ID;
        cin >> ID;
        Request tmp(ID, unif(gen)); //init ID and weight
        request.push_back(tmp);
    }
    for(int i = 0; i < nresources; i++){
        int ID;
        cin >> ID;
        Resource tmp(ID);
        resource.push_back(tmp);
    }
    cin >> nedges;
    Edge edge[nedges];
    for(int i=0; i < nedges; i++){  //read edges
        cin >> edge[i].id >> edge[i].from >> edge[i].to;
        edge[i].w = request[edge[i].from].getWeight();
        graph[edge[i].to].push(edge[i]);
    }
    for(int i=0; i < resource.size(); i++){
        if(resource[i].getmatched())
            continue;
        while(!graph[i].empty()){   //
            Edge tmp = graph[i].top();
            graph[i].pop();
                //cout << tmp.from << " " << tmp.to << endl;
            if(resource[i] ->* request[tmp.from]){
                Resource::count++;
                break;
            }
        }
    }
}

