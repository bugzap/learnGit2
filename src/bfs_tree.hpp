#pragma once
#include <iostream>
#include <queue>
#include "Node.hpp"


namespace graph
{

    
    void BFS(Node* aRoot){
        if (!aRoot){
            return;
        }
        std::queue<Node*> q;
        q.push(aRoot);

        while(!q.empty()){
			Node* n = q.front();
			q.pop();
            std::cout << n->value;
            if (n->left){
                q.push(n->left);
            }
            if (n->right){
                q.push(n->right);
            }
        }

    };

    
    // in order traversal;
    void DFS (Node* aRoot){
        if (aRoot == nullptr){
            return;
        }
        
        DFS(aRoot->left);
        
        std::cout << aRoot->value;

        DFS(aRoot->right);        

    }




}
