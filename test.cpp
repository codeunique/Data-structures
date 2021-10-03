#include<iostream>
#include"graph.hpp"

using namespace std;

int main()
{
    Graph g (6,10,'U');
    g.buildAdjList();
    g.displayAdjList();
    g.dfs(0);
    return 0;
}