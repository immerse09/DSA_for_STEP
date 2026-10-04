#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> * l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){ //u---v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u=0; u<V; u++){ //0, 1, 2, 3, 4
            list<int> neighbors = l[u];
            cout << u << " : ";
            for(int v : neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    


//    DFS
     void dfsHelper(int u, vector<bool> &vis){ //O(V+E)
        cout << u << " ";
        vis[u] = true;
        list<int> neighbors = l[u];

        for(int v : neighbors){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
        dfsHelper(0, vis); //starting pt =1
        cout << endl;
    }
}
cout << endl;
    }
};

int main(){
    Graph graph(7);

    // undirected 
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    // 1st way
    // vector<bool> vis(7, false);
    // graph.dfs(0, vis);

    // 2nd way
    graph.dfs();
   
    return 0;
}