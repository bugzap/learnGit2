#include <iostream>
#include "LinkedList.hpp"

using namespace utils;

void deleteNextNode(LinkedList* node){
    LinkedList* nextNode = node->next->next;
    node->next = nextNode;
}

void deleteKthLastNode(LinkedList* list, int k){
    LinkedList* it1 =  list;
    int step = 0;
    while(step <= k-1){
        it1 = it1->next;
        step++;
    }
    LinkedList* it2 = list;
    while(true){
        if (it1->next == nullptr){
            break;
        }
        it1 = it1->next;
        it2 = it2->next;
    }
    deleteNextNode(it2);
}


int main()
{
    LinkedListPool pool;
    LinkedList* list = pool.getLinkedList({1, 2,3,4, 5,6});
    list->print();
    deleteKthLastNode(list, 2);
    list->print();
}