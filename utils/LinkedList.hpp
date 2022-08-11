#pragma once

#include <vector>
#include <iostream>
#include <unordered_set>

namespace utils{

    struct LinkedList{

    LinkedList(int aVal)
    :   
    Val(aVal),
    next(nullptr)
    {

    }
    void print()
    {       
        LinkedList* itr = this;
        std::string chainStr = "";
        while(itr){
            std::cout  << chainStr <<  itr->Val ;
            itr = itr->next;            
            chainStr = "->";
        }
    }

    int Val;
    LinkedList* next;
};
    struct LinkedListPool{

        LinkedList* getLinkedList(const std::vector<int>& nums)
        {
            LinkedList* list = getNode(-1);
            LinkedList* result= list;
            for (int n : nums){
                LinkedList* newNode = getNode(n);
                list->next = newNode;
                list = newNode;
            }
            return result->next;
        }

        LinkedList* getNode(int val){
            LinkedList* thisNode = new LinkedList(val);
            fNodes.insert(thisNode);
            thisNode->next = nullptr;
            return thisNode;
        }
        ~LinkedListPool()
        {
            for (auto& n : fNodes)
            {
                delete n;
            }
        }
        private:
        std::unordered_set<LinkedList*> fNodes{};
    };


}