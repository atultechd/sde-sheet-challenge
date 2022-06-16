#include <bits/stdc++.h> 
/****************************************************************
 
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

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead){
    if(firstHead == NULL || secondHead == NULL) return -1;
    Node *a = firstHead;
    Node *b = secondHead;
    while(a != b){
        if(a == NULL) a = secondHead;
        else a = a->next;
        if(b == NULL) b = firstHead;
        else b = b->next;      
    }
    if(a == NULL) return -1;
    return a->data;
    
       
}