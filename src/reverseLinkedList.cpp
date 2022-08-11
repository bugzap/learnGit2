

#include "LinkedList.hpp"

#include <iostream>
utils::LinkedList* reverseLinkedList(utils::LinkedList* aList)
{
    aList->print();
    std::cout << std::endl;
    if (!aList || !aList->next){
        return aList;
    }
    using namespace utils;
    LinkedList* last = aList;
    int lastIdx  = 0;
    while(last->next){
        lastIdx++;
        last = last->next;        
    }

    
    LinkedList* result = last;

    while(lastIdx > 0){
        LinkedList* workerNode = aList;
        for (int i = 0; i < lastIdx - 1; i++){
            workerNode = workerNode->next;     
        }
        last->next = workerNode;
        last = last->next;
        lastIdx--;
    }

    last->next = nullptr;

    result->print();
    return result;
}
#if 0
int main()
{
    using namespace utils;
    LinkedListPool llPool;
    LinkedList* l1 = llPool.getNode(1);
    LinkedList* l2 = llPool.getNode(2);
    LinkedList* l3 = llPool.getNode(3);


    l1->next = l2;
    l2->next = l3;
    reverseLinkedList(l1);

    return 0;
}
#endif