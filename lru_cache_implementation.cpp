#include<bits/stdc++.h>
class LRUCache{
public:
    class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
        
    };
    
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    int cap;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node *newnode){
        Node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(Node *delnode){
        Node *d_prev = delnode->prev;
        Node *d_next = delnode->next;
        d_prev->next = d_next;
        d_next->prev = d_prev;
    }

    int get(int key){
        if(m.find(key) != m.end()){
            Node *res_node = m[key];
            int res = res_node->val;
            m.erase(key);
            deletenode(res_node);
            addnode(res_node);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value){
        if(m.find(key) != m.end()){
            Node *existing_node = m[key];
            m.erase(key);
            deletenode(existing_node);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        m[key] = head->next;
    }
};
