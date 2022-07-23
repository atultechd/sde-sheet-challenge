#include<bits/stdc++.h>
class LFUCache{
public:
    class node{
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    int cap;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    unordered_map<int,node*> m;
    unordered_map<int,int> freq;
    
    LFUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add_node(node *newnode){
        node *temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        temp->prev = newnode;
        newnode->prev = head;
    }
    
    void delete_node(node *delnode){
        node *d_prev = delnode->prev;
        node *d_next = delnode->next;
        d_prev->next = d_next;
        d_next->prev = d_prev;
    }

    int get(int key){
        if(cap == 0) return -1;
        if(m.find(key) != m.end()){
            int result = 0;
            node *temp = m[key];
            result = temp->val;
            m.erase(key);
            delete_node(temp);
            add_node(temp);
            m[key] = head->next;
            freq[key]++;
            return result;
        }
        return -1;
    }

    void put(int key, int value){
        if(m.find(key) != m.end()){
            node *newnode = m[key];
            delete_node(newnode);
            m.erase(key);
            freq[key]++;
        }
        if(m.size() == cap && cap != 0){
            int mini = 1000;
            node *del_node;
            for(auto x: freq){
                mini = min(mini, x.second);
            }
            int count = 0;
            for(auto x: freq){
                if(x.second == mini) count ++;
            }
            if(count == 1){
                int key_val = 0;
                for(auto x : freq){
                    if(x.second == mini){
                        del_node = m[x.first];
                        key_val = x.first;
                        break;
                    }
                }
                m.erase(key_val);
                freq.erase(key_val);
                delete_node(del_node);
            }
            else{
                m.erase(tail->prev->key);
                delete_node(tail->prev);
                freq.erase(tail->prev->key);
            }
        }
        add_node(new node(key, value));
        m[key] = head->next;
        freq[key]++;
    }
};
