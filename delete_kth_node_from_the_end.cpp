#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K){
    if(head == nullptr || K == 0) return head;
    LinkedListNode<int> *curr = head;
    int n=0;
    while(curr!=nullptr){
        n++;
        curr=curr->next;
    }
    int a = n-K;
    curr = head;
    LinkedListNode<int> *prev = nullptr;
    while(a > 0){
        prev = curr;
        curr = curr->next;
        a --;
    }
    if(prev != nullptr){
        prev->next = curr->next;
    }
    else{
        head = head->next;
    }
    return head;
}





