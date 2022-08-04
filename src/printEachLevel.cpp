#include <map>
#include <vector>
#include <iostream>
#include "printEachLevel.hpp"
#include "Node.hpp"

namespace{

    class NodeCollector{
        public:
        NodeCollector()
        :
        fLevel2Nodes()
        {

        }

        void add(int level, graph::Node* aNode){
            fLevel2Nodes[level].push_back(aNode);
        }
        void print()
        {
            for (const auto& [level, nodes] : fLevel2Nodes){
                std::cout << "Level " << level << ":";
                for (const auto& n : nodes){
                    std::cout << n->value;
                    std::cout << " ";
                }
                std::cout << std::endl;
            }
        }

        private:
        using NodeList = std::vector<graph::Node*>;
        std::map<int, NodeList> fLevel2Nodes;
    };
    void printEachLevelHelper(graph::Node* aNode, int aLevel, NodeCollector& nc)
    {
        if (!aNode){
            return;
        }
        if (aNode->left){
            printEachLevelHelper(aNode->left, aLevel + 1, nc);
        }
        if (aNode->right){
            printEachLevelHelper(aNode->right, aLevel + 1, nc);
        }
        nc.add(aLevel, aNode);
    }
}

void graph::printEachLevel(Node* aRoot)
{
    NodeCollector nc;
    printEachLevelHelper(aRoot, 0, nc);
    nc.print();    
        
}

