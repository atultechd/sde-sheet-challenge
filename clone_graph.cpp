#include<bits/stdc++.h>
/***************************************************************************

    Class for graph node is as follows:

    class graphNode
    {
        public:
            int data;
        vector<graphNode *> neighbours;
        graphNode()
        {
            data = 0;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val)
        {
            data = val;
            neighbours = vector<graphNode *>();
        }

        graphNode(int val, vector<graphNode *> neighbours)
        {
            data = val;
            this->neighbours = neighbours;
        }
    };

******************************************************************************/

graphNode *dfs(graphNode *curr, unordered_map<graphNode*, graphNode*> &m){

//     creating adjacency list.
    vector<graphNode*> neighbour;
    
//     creating clone of current node.
    graphNode* clone = new graphNode(curr->data);
    
//     map me store karo node and uske clone ko.
    m[curr] = clone;

//     check karo current node k neighbours k liye bhi
    for(auto it: curr->neighbours){
//         agar present hai map me then jo adjacency list create kiya tha na, usme daalo clone ko.
        if(m.find(it) != m.end())
            neighbour.push_back(m[it]);

//         agar neighbouring node map me nahi present tou uske liye dfs() call karo. 
        else   
            neighbour.push_back(dfs(it,m));
    }
//     clone k neighbours ko neighbour list assign kardo at the end, kyonki iske bhi neighbour
//     current k neighbours k similar honge.
    clone->neighbours = neighbour;
    
//     last me clone ko return kardo.
    return clone;
}


graphNode *cloneGraph(graphNode *node){

//     unordered_map create karlo
    unordered_map<graphNode*, graphNode*> m;

//     check karo k given node agar null hai tou null return kardo.
    if(node == NULL) return NULL;

//     agar single node hai without neighbours tou sirf uska clone banake return kardo.
    if(node->neighbours.size() == 0){

        graphNode *clone = new graphNode(node->data);

        return clone;
    }

//     return karo dfs() function ko.
    return dfs(node, m);
}