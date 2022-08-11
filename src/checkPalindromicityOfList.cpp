#include "LinkedList.hpp"
#include "reverseLinkedList.hpp"

using namespace  utils;
bool  checkPalindrome(LinkedList* list)
{
    LinkedList* head = list;
    int size = 0;
    while(head){
        head = head->next;
        size++;
    }
    LinkedList* half = list;
    int step = 0;
    while(step < size/2)
    {
        half = half->next;
        step++;
    }
    if (size%2 != 0){
        half= half->next;
        step++;
    }
    LinkedList* revSecondHalf = reverseLinkedList(half);
    LinkedList* firstHalf = list;
    while(step > 0){
        if (firstHalf->Val != revSecondHalf->Val){
            return false;
        }
        firstHalf = firstHalf->next;
        revSecondHalf = revSecondHalf->next;
        step--;
    }
    return true;
}



int main()
{
    LinkedListPool pool;
    LinkedList* list = pool.getLinkedList({1, 2,3,3, 2,1});
    std::cout << checkPalindrome(list);
}