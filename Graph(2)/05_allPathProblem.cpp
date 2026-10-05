#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> * l;
    bool isUndir;

    public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){ //u--->v
        l[u].push_back(v);
        if(isUndir)
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

    bool undirCycleHelper(int src, int par, vector<bool> &vis){ //O(V+E)
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){
                    return true;
                }
            } else {
                if(v != par){ //cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool> vis(V, false);
        return undirCycleHelper(0, -1, vis);
    }

    // original logic in dir 
    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPth[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(dirCycleHelper(v, vis, recPath)){
                    return true;
                }
            } else {
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }

    // Bipartite
    bool isBipartite(){
        queue<int> q;
        vector<bool> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    color[v] = !color[curr]; //opposite color
                    q.push(v);
                } else {
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void pathHelper(int src, int dest, vector<bool> &vis, string &path){ //O(V+E)
        if(src == dest){
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                pathHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest){
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    
}
};



int main(){
    Graph graph(6, false);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPaths(5, 1);

    return 0;
}