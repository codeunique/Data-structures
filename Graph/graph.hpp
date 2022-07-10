#ifndef GRAPH_H
#define GRAPH_H
// Implementing graph using an adjacency list.
#include<vector>
using namespace std;
class Graph
{
    private:
    vector<vector<int>> adj;
    vector<bool> vis;
    int nVertices,nEdges;
    char type_of_graph;
    public:
    Graph(int V,int E,char type)
    {
        this->nVertices = V;
        this->nEdges = E;
        adj.resize(V);
        vis.resize(V);
        for(int i=0;i<V;i++){
            vis[i] = false;
        }
        this->type_of_graph = type;

    }

    void buildAdjList();
    void displayAdjList();
    void dfs(int);

};
#endif