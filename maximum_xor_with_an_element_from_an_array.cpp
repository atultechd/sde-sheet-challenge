#include<bits/stdc++.h>

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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){

    Trie trie;

    vector<int> ans(queries.size(), 0);

    vector<pair<int,pair<int,int>>> off_queries;

    sort(arr.begin(),arr.end());

    int ind = 0;

    for(auto it : queries){

        off_queries.push_back({it[1],{it[0],ind++}});
    }

    sort(off_queries.begin(), off_queries.end());

    int i=0;

    for(auto &it: off_queries){

        int ai = it.first;

        int xi = it.second.first;

        int index = it.second.second;

        while(i < arr.size() && arr[i] <= ai){

            trie.insert(arr[i]);

            i++;
        }

        if(i != 0){

            ans[index] = trie.getmax(xi);
        }

        else ans[index] = -1;
    }
    
    return ans;
}