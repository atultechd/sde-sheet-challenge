/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node* link[26];
    bool flag = false;
    bool containkey(char c){
        return (link[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        link[c-'a'] = node;
    }
    Node * get(char c){
        return link[c-'a'];
    }
    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
private: 
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *dummy = root;
        for(int i=0; i<word.size(); i++){
            if(!dummy->containkey(word[i])){
                dummy->put(word[i], new Node());
            }
            dummy = dummy->get(word[i]);
        }
        dummy->setend();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *dummy = root;
        for(int i=0; i<word.size(); i++){
            if(!dummy->containkey(word[i])){
                return false;
            }
            dummy = dummy->get(word[i]);
        }
        return dummy->isend();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *dummy = root;
        for(int i=0; i<prefix.size(); i++){
            if(!dummy->containkey(prefix[i])){
                return false;
            }
            dummy = dummy->get(prefix[i]);
        }
        return true;
    }
};