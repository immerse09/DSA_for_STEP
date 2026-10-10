#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
    public:
    int n;
    vector<int> par;
    vector<int> rank;

    DisjointSet(int n){
        this->n = n;

        for(int i=0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]); //path compression
    }

    void unionByRank(int u, int v){
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]){
            par[parV] = parU;
            rank[parU]++;
        } else if(rank[parU] > rank[parV]){
            par[parV] = parU;
        } else {
            par[parU] = parV;
        }
    }

    void getInfo(){
        for(int i=0; i<n; i++){
        cout << i << ": " << par[i] << " , " << rank[i] << endl;
        }
    }
};

class Edge {
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public: 
    vector<Edge> edges;
    int V;

    Graph(int V){
        this->V = V;

        for(int i=0; i<V; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }

    void addEdge(int u, int v, int wt){
        edges.push_back(Edge(u, v, wt));
    }
}


int main(){
    DisjointSet dj(6);
    dj.unionByRank(0, 2);
    cout << dj.find(2) << endl;
    dj.unionByRank(1, 3);
    dj.unionByRank(2, 5);
    dj.unionByRank(0, 3);
    cout << dj.find(2) << endl;
    dj.unionByRank(0, 4);

    dj.getInfo();

    return 0;
}