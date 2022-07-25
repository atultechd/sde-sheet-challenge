#include<bits/stdc++.h>

// Brute force approach
int distinctSubstring(string &word) {

    set<string> st;

    for(int i=0; i<word.size(); i++){

        string str = "";

        for(int j=i; j<word.size(); j++){

            str = str + word[j];

            st.insert(str);
        }
    }

    return st.size();
}

// ............................................................

// Using Trie
struct Node{

    Node *links[26];

    bool containskey(char ch){

        return (links[ch -'a'] != NULL);
    }

    void put(char ch, Node *node){

        links[ch-'a'] = node;
    }

    Node *get(char ch){

        return links[ch-'a'];
    }
    
};

int distinctSubstring(string &word) {

    int count = 0;

    Node *root = new Node();

    for(int i=0; i<word.size(); i++){

        Node *node = root;

        for(int j=i; j<word.size(); j++){

            if(!node->containskey(word[j])){

                count ++;

                node->put(word[j], new Node());
            }

            node = node->get(word[j]);
        }
    }
    return count;
}






