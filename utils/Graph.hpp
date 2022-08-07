#pragma once
#include <vector>
#include <iostream>
#include <unordered_set>
#include <map>


namespace utils
{

    class Graph
    {
        private:
        std::map<int, std::vector<int>> fGraph;
        std::unordered_set<int> fVisited;
    public:
        int u;
        Graph(int startingVertex) 
        :
        fGraph(),
        fVisited(),
        u(startingVertex)
        {

        }

        void clearVisited(){
            fVisited.clear();
        }
        
        const std::vector<int>& getNeighbours(int u) const{
            auto found = fGraph.find(u);;
            return found->second;
        }
        void addEdge(int u, int v)
        {
            fGraph[u].push_back(v);
            // for directed, comment below line
            fGraph[v].push_back(u);
        }
        void visit(int u){
            fVisited.insert(u);
            std::cout << u << std::endl;
        }
        bool visited(int u) const{
            return (fVisited.find(u) != fVisited.end());
        }
    };
}