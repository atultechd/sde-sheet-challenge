#include<bits/stdc++.h>

struct Node{

    Node *links[26];

    bool flag = false;

    bool containskey(char ch){

        return (links[ch-'a'] != NULL);
    }

    Node *get(char ch){

        return links[ch-'a'];
    }

    void put(char ch, Node *node){

        links[ch-'a'] = node;
    }
    
    Node *setend(){

        flag = true;
    }
    
    bool isend(){

        return flag;
    }
};


class Trie{

    private: Node *root;

    public:

    Trie(){

        root = new Node();
    }
    
    void insert(string &word){

        Node *node = root;

        for(int i=0; i<word.size(); i++){

            if(!node->containskey(word[i])){

                node->put(word[i],new Node());
            }

            node = node->get(word[i]);
        }

        node->setend();
    }
    
    bool check_all_prefix(string &word){

        Node *node = root;

        for(int i=0; i<word.size(); i++){

            if(!node->containskey(word[i])){

                return false;
            }

            else{

                node = node->get(word[i]);

                if(!node->isend()) return false;
            }
        }

        return node->isend();
    }
};


string completeString(int n, vector<string> &a){

    Trie trie;

    for(string& word :a){

        trie.insert(word);
    }

    string longest = "";

    for(string& word :a){

        if(trie.check_all_prefix(word)){

            if(word.size() > longest.size() || (word.size() == longest.size() && word < longest)){

                longest = word;
            }
        }
    }

    if(longest == "") return "None";
    
    return longest;
}






