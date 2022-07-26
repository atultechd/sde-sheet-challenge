// Brute force approach
int maximumXor(vector<int> a){

    int maxi = 0;

    for(int i=0; i<a.size()-1; i++){

        for(int j=i+1; j<a.size(); j++){

            int ans = a[i] ^ a[j];

            maxi = max(maxi, ans);
        }
    }
    return maxi;
}


// .................................................................


// Optimised approach using trie
struct Node{

    Node *links[2];

    bool containskey(int bit){

        return (links[bit] != NULL);
    }

    Node *get(int bit){

        return links[bit];
    }

    void put(int bit, Node *node){

        links[bit] = node;
    }
};

class Trie{

    private: Node *root;

    public:

    Trie(){

        root = new Node();
    }

    void insert(int num){

        Node *node = root;

        for(int i=31; i>=0; i--){

            int bit = (num >> i) & 1;

            if(!node->containskey(bit)){

                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getmax(int num){

        Node *node = root;

        int max_num = 0;

        for(int i=31; i>=0; i--){

            int bit = (num >> i) & 1;

            if(node->containskey(!bit)){

                max_num = max_num | (1 << i);

                node = node->get(!bit);
            }

            else{

                node = node->get(bit);
            }
        }
        return max_num;
    }
};


int maximumXor(vector<int> a){

    int n = a.size();

    Trie trie;

    for(int i=0; i<n; i++){

        trie.insert(a[i]);
    }

    int maxi = 0;

    for(int i=0; i<n; i++){

        maxi = max(maxi, trie.getmax(a[i]));
    } 

    return maxi;
}