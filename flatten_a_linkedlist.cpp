#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
  int data;
  Node* next;
  Node* child;

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->child = NULL;
  }
};

*****************************************************************/
Node* merge_list(Node* list1, Node* list2){

    Node* temp = new Node(0);
    Node* res = temp;

    while(list1 != NULL && list2!= NULL){
        if(list1->data < list2->data){
            temp->child = list1;
            temp = temp->child;
            list1 = list1->child;
        }
        else{
            temp->child = list2;
            temp = temp->child;
            list2 = list2->child;
        }
    }

    // remaining nodes of list1 and list2
    // are to be merged at last of temp node.
    if(list1) temp->child = list1;
    else temp->child = list2;

    res->child->next = NULL;

    return res->child;
}

Node* flattenLinkedList(Node* head) {
    if(head == NULL || head->next == NULL)return head;
    head->next = flattenLinkedList(head->next);
    head = merge_list(head, head->next);
    return head;
}
