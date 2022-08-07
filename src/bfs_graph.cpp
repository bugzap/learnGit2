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

int main()
{
    /*
    utils::Graph g(0);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    */
   utils::Graph g(2);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "BFS" << std::endl;
    bfs(&g);
    g.clearVisited();
    std::cout << "DFS" << std::endl;
    dfs(&g);
}