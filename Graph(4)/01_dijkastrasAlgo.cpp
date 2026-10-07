#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

// this class store v of u and wt
class Edge {
public:
    int v; //destination
    int wt; //weight

    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }

};

void dijkastra(int src, vector<vector<Edge>> graph, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
    // pair (dist[v], v);
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

       vector<Edge> edges = graph[u];
       for(Edge e : edges){ //e.v, e.wt
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
       }
    }

    for(int d : dist){
        cout << d << " ";
    }
    cout << endl;
}

int main(){
    // directed weighted graph with non-negative weights
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[1].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[1].push_back(Edge(2, 4));
    graph[1].push_back(Edge(2, 4));

    dijkastra(0, graph, V); //0 2 3 8 6 9
    dijkastra(1, graph, V); //inf 0 1 6 4 7
    return 0;

}