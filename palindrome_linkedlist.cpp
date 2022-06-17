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
LinkedListNode<int> *reverse_list(LinkedListNode<int> *head){
    LinkedListNode<int> *pre = NULL;
    LinkedListNode<int> *nex = NULL;
    
    while(head){
        nex = head->next;
        head->next = pre;
        pre = head;
        head = nex;
    }
    return pre;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)return true;

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;


    // To find the middle of the list so that right half
    // would be easy to traverse.
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Calling reverse function to find reverse of right half.
    slow->next = reverse_list(slow->next);

    slow = slow->next;

    // This code is to check whether left half list is equal to 
    // right half or not.
    while(slow!= NULL){
        if(head->data != slow->data) return false;
        slow = slow->next;
        head = head->next;
    }

    return true;
}