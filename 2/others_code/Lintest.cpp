#include <bits/stdc++.h>
using namespace std;
#define max_resource 300
int randomSeed;                  // from the parameter of main function
default_random_engine generator; // get random number for weight
uniform_real_distribution<double> unif(0.0, 1.0);
class Request
{
    int id;
    bool matched = false; // the request is matched or not
    int resourceID;
    double weight;

public:
    friend class Resource;
    void newrequest(int ID) // set the new request
    {
        id = ID;
        weight = unif(generator);
    }
    double getweight() // get the weight of the request
    {
        return weight;
    }
};
class Resource
{
    int id;
    bool matched = false; // the resource is matched or not
    int requestID;

public:
    bool operator->*(Request &b) // check whether both of them are un-matched
    {
        if (b.matched != false ||
            matched != false) // If one of them is matched, return false
            return false;
        matched = b.matched = true; // If they are, then match them and return true
        return true;
    }
    void newresource(int ID) // set the new resource
    {
        id = ID;
    }
    bool getmatched() // get the resource is matched or not
    {
        return matched;
    }
};
vector<Request> Reque;
vector<Resource> Resour;
priority_queue<pair<double, int>> edge[max_resource]; // store all edges
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    answer;
void timeslot()
{
    int timeslotID, edgeID;
    int requestNumber, resourceNumber, edgeNumber;
    int requestID, resourceID;
    cin >> timeslotID >> requestNumber >> resourceNumber;
    for (int i = 0; i < requestNumber; i++) // input the new requests
    {
        cin >> requestID;
        Request tmp;
        tmp.newrequest(requestID);
        Reque.push_back(tmp);
    }
    for (int i = 0; i < resourceNumber; i++) // input the new resources
    {
        cin >> resourceID;
        Resource tmp;
        tmp.newresource(resourceID);
        Resour.push_back(tmp);
    }
    cin >> edgeNumber;
    for (int i = 0; i < edgeNumber; i++) // input the new edges
    {
        cin >> edgeID >> requestID >> resourceID;
        edge[resourceID].push(make_pair(Reque[requestID].getweight(), requestID));
    }
    for (int i = 0; i < Resour.size(); i++)
    {
        if (Resour[i].getmatched())
            continue;
        while (!edge[i].empty())
        {
            pair<double, int> tmp = edge[i].top();
            edge[i].pop();
            if (Resour[i]->*Reque[tmp.second]) // if Resour[i] and Reque[tmp.second]
            // are unmatched
            {
                answer.push(make_pair(tmp.second, i)); // push into the answer
                break;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int timeSlots;
    freopen("request1.txt", "r", stdin);
    freopen("LINresult.txt", "w", stdout);
    randomSeed = atoi(argv[1]);
    generator = default_random_engine(randomSeed);
    cin >> timeSlots;
    for (int i = 0; i < timeSlots; i++)
        timeslot();
    cout << answer.size() << endl;
    while (!answer.empty())
    {
        pair<int, int> tmp = answer.top();
        answer.pop();
        cout << tmp.first << "\t" << tmp.second << endl;
    }
    cout << "------------" << endl; /////////
    for(auto i:Reque){
        cout << i.getweight() << endl;
    }/////
    return 0;
}
