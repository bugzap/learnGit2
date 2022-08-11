#include "LinkedList.hpp"


void copyOver(utils::LinkedList* l,  utils::LinkedListPool* lp, utils::LinkedList* mergedList){
    while(l){
        mergedList->next = lp->getNode(l->Val);
        l = l->next;
        mergedList = mergedList->next;
    }

}

utils::LinkedList* mergeLinkedLists(utils::LinkedList* l1, utils::LinkedList* l2, utils::LinkedListPool* lp)
{
    using namespace utils;
    LinkedList* mergedList = lp->getNode(-1);
    LinkedList* result = mergedList;
    while(l1 && l2){        
        LinkedList* newNode;
        if (l1->Val < l2->Val){
            newNode = lp->getNode(l1->Val);
            l1 = l1->next;
        }
        else{
            newNode = lp->getNode(l2->Val);
            l2 = l2->next;
        }
        mergedList->next = newNode;
        mergedList = mergedList->next;

    }
    copyOver(l1, lp, mergedList);
    copyOver(l2, lp ,mergedList);

    result = result->next;
    return result;
}


int main()
{
    utils::LinkedListPool lp;
    utils::LinkedList* l1 = lp.getNode(1);
    l1->next  =lp.getNode(4);
    l1->next->next = lp.getNode(5);
    utils::LinkedList* l2 = lp.getNode(1);
    l2->next = lp.getNode(4);
    l2->next->next = lp.getNode(6);

    utils::LinkedList* merged = mergeLinkedLists(l1, l2, &lp);
    merged->print();
    return 0;
}