#include "Graph.hpp"
#include <queue>

void bfs(utils::Graph *g)
{
    std::queue<int> q;
    q.push(g->u);
    g->visit(g->u);
    while (!q.empty())
    {
        int thisVertex = q.front();
        q.pop();
        for (int v : g->getNeighbours(thisVertex))
        {
            if (!g->visited(v))
            {
                g->visit(v);
                q.push(v);
            }
        }
    }
}

void dfsHelper(utils::Graph *g, int u)
{
    g->visit(u);
    for (int v : g->getNeighbours(u))
    {
        if (!g->visited(v))
        {
            dfsHelper(g, v);
        }
    }
}

void dfs(utils::Graph *g)
{
    dfsHelper(g, g->u);
}

void doTraversals(utils::Graph* g){
        std::cout << "BFS" << std::endl;
        bfs(g);
        g->clearVisited();
        std::cout << "DFS" << std::endl;
        dfs(g);
        g->clearVisited();
}

int main()
{
    
    utils::Graph g1(0);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(1, 4);
    g1.addEdge(1, 5);
    g1.addEdge(2, 5);
    g1.addEdge(3, 6);
    
   utils::Graph g2(2);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    g2.addEdge(2, 3);
    g2.addEdge(3, 3);

    doTraversals(&g1);
    doTraversals(&g2);
}