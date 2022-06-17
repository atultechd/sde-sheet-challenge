#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
      public:
          int data;
          Node *next;
          Node(int data)
          {
              this->data = data;
              this->next = NULL;
          }
    };

********************************/


Node *rotate(Node *head, int k) {
    if(head == NULL || head->next == NULL || k==0) return head;
    Node *temp = head;
    int n = 1;
    while(temp->next && ++n){
        temp = temp->next;
    }
    
    temp->next = head;
    k = k%n;
    k = n-k;
    while(k--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}