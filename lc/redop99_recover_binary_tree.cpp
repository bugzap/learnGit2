#include "Node.hpp"

using namespace graph;
class Solution {
public:
    
    Node* badNode1{nullptr};
    Node* badNode2{nullptr};

    void addBadNode(Node* n1, Node* n2){
                badNode1 = n1;
                badNode2 = n2;

    }
    void addBadNode(Node* n1){
        if (!badNode1){
            badNode1 = n1;
        }
        else{
            badNode2 = n1;
        }
    }

    void fixUpBadNodes()
    {
        
        int tmp = badNode1->value;
        badNode1->value = badNode2->value;
        badNode2->value = tmp;
    }
    void validate(Node* n, int minValue, int maxValue){
        if (!n){
            return;
        }
        bool success = badNode1 && badNode2;
        if (success){
            return;
        }
        if ((n->value < minValue))
        {
            addBadNode(n);
        }
        if (n->value > maxValue){
            addBadNode(n);
        }
        if (n->left){
            if (n->value < n->left->value){
                addBadNode(n, n->left);
            }
            validate(n->left, minValue, n->value);
        }
        if (n->right){
            if (n->right->value < n->value){
                addBadNode(n, n->right);
            }
            validate(n->right, n->value, maxValue);
        }

    }
    void recoverTree(Node* root) {
        validate(root, INT_MIN,  INT_MAX);
        fixUpBadNodes();
    }
};