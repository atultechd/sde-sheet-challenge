#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *cur = head;
    while(cur){
        LinkedListNode<int> *temp = cur->next;
        LinkedListNode<int> *node = new LinkedListNode<int> (cur->data);
        cur->next = node;
        node->next = temp;
        cur = temp;
    }
    cur = head;
    while(cur){
        if(cur->next != NULL){
            cur->next->random = (cur->random != NULL) ? cur->random->next : NULL;
        }
        cur = cur->next->next;
    }
    cur = head;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0); 
    LinkedListNode<int> *tail = dummy;
    while(cur){
        tail->next = cur->next;
        tail = tail->next;
        cur->next = tail->next;
        cur = cur->next;
    }
    return dummy->next;
}
