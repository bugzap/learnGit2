#pragma once
#include <list>
#include <iostream>
#include <unordered_set>
#include <map>


namespace utils
{

    class Graph
    {
        public:
        using AdjacencyList = std::list<int>;
        private:
        std::map<int, AdjacencyList> fGraph;
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
        
        const AdjacencyList& getNeighbours(int u) const{
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