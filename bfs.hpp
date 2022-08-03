#pragma once
#include <iostream>

namespace graph
{

    struct Node{
        Node* left;
        Node* right;
        int value;
    }
    void BFS(Node* aRoot){
        
    };

    void DFS (Node* aRoot){
        if (aRoot == nullptr){
            return;
        }
        
        DFS(aRoot->left);
        
        std::cout << aRoot->value;

        DFS(aRoot->right);        

    }


}