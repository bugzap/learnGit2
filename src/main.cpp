#include <iostream>
#include "bfs.hpp"
#include "Node.hpp"
#include "printEachLevel.hpp"

using namespace graph;
class NodePool{
    public:
    NodePool()
    :
    fNodes()
    {

    }
    Node* getNode(int value){
        Node* n = new Node;
        n->value = value;
        fNodes.push_back(n);
        return n;
    }
    ~NodePool()
    {
        for  (Node* n : fNodes){
            delete n;
        }
    }
    private:
        std::vector<Node*> fNodes;
};
int main()
{
    NodePool nPool;
    std::vector<Node*> nVec;
    nVec.reserve(7);
    for (int i : {0,1,2,3,4,5,6}){
        nVec.push_back(nPool.getNode(i));
    }
    nVec[0]->left = nVec[1];
    nVec[0]->right = nVec[2];

    nVec[1]->left = nVec[3];
    nVec[1]->right = nVec[4];

    nVec[2]->left = nVec[5];
    nVec[3]->left = nVec[6];

	graph::BFS(nVec[0]);
	std::cout << std::endl;
	graph::DFS(nVec[0]);
	std::cout << std::endl;

    printEachLevel(nVec[0]);
    return 0; 
} 