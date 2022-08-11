#include "LinkedList.hpp"

using namespace utils;
void removeDuplicatesFromSortedList(LinkedList* list)
{
    LinkedList* it1 = list;
    while(it1 && it1->next)
    {
        if (it1->next->Val != it1->Val){
            it1 = it1->next;
        }
        else{
            it1->next = it1->next->next;
        }
    }
}


int main()
{
    LinkedListPool lp;
    LinkedList* list = lp.getLinkedList({1,2,2,2,3,4,5,5,5});
    removeDuplicatesFromSortedList(list);
    list->print();
}