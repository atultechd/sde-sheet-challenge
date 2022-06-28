#include<bits/stdc++.h>
struct Node{
    Node *links[26];
    int visits;
    char ch;
    int word_end;
    
    Node(char c = ' '){
        memset(links, 0, sizeof(links));
        visits = 0;
        ch = c;
        word_end = 0;
    }
};

class Trie{
    Node* root;
    stack<Node*> stk;
    public:

    Trie(){
        root = new Node();
    }
    
    ~Trie(){
        delete_trie(root);
    }
    
    void delete_trie(Node *root){
        if(root == NULL)return;
        for(int i=0; i<26; i++){
            delete_trie(root->links[i]);
        }
        delete root;
    }
    

    void insert(string &word){
        Node *cur = root;
        int n = word.length();
        int i=0;
        while(i<n){
            int index = word[i]- 'a';
            if(cur->links[index]== NULL){
                cur->links[index] = new Node(word[i]);
            }
            cur = cur->links[index];
            cur->visits = cur->visits + 1;
            i++;
        }
        cur->word_end = cur->word_end + 1;
    }
    
    
    void clear_stack(){
        while(!stk.empty()) stk.pop();
    }
    
    
    Node *search(string &word, bool erase =false){
        if(erase){
            stk.push(root);
            clear_stack();
        }
        Node *cur = root;
        int n = word.length();
        int i=0;
        while(i<n){
            int index = word[i]-'a';
            if(cur->links[index] == NULL)return NULL;
            cur= cur->links[index];
            if(erase) stk.push(cur);
            i++;
        }
        return cur;
    }

    
    int countWordsEqualTo(string &word){
        Node *cur = search(word);
        if(cur)return cur->word_end;
        return 0;
    }
    

    int countWordsStartingWith(string &word){
        Node *cur = search(word);
        if(cur)return cur->visits;
        return 0;
    }
    

    void erase(string &word){
        int n=word.length();
        Node *cur = search(word,true);
        cur->word_end = cur->word_end - 1;
        bool delete_prev = false;
        while(n--){
            cur = stk.top();
            stk.pop();
            cur->visits = cur->visits - 1;
            if(delete_prev){
                int index = word[n+1]-'a';
                delete cur->links[index];
                cur->links[index] = NULL;
            }
            if(cur->visits==0)delete_prev = true;
            else delete_prev = false;
        }
    }
};
