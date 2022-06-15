#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *new_node = new Node<int>(0);
    Node<int> *current = new_node;
    while(first != NULL && second != NULL){
        if(first->data < second->data){
            current->next = first;
            first = first->next;
        }   
        else{
            current->next = second;
            second = second->next;
        }
        current = current->next;
    }
    
    if(first != NULL){
        current->next = first;
        first = first->next;
    }
    if(second != NULL){
        current->next = second;
        second = second->next;
    }
    return new_node->next;
}



