#include<iostream>
#include"./graph.hpp"

void Graph:: buildAdjList()
{
    for(int i=0;i<nEdges;i++)
    {
        int u,v;
        std::cin>>u>>v;
        if(type_of_graph=='D')// If the given graph is directed.
          adj[u].push_back(v);// there is and edge from u to v.
        else if(type_of_graph=='U')
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else 
         std::cout<<"!! Enter a valid type of graph.";
    }
}

void Graph::displayAdjList()
{
    for(int i=0;i<nVertices;i++)
    {
        std::cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++)
          std::cout<<adj[i][j]<<",";
        std::cout<<"\n";  
    }
    
}

void Graph:: dfs(int root)
{
    if(!vis[root]){
        vis[root] = true;
        cout<<root;
        for(int child: adj[root]){
            dfs(child);
        }
    }

}