#include<bits/stdc++.h>
class Stack {
  queue<int>q;
    int sizee;
   public:
    Stack() {
        sizee = -1;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        sizee++;
        q.push(element);
        for(int i=0; i<sizee; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(!q.empty()){
            int popped = q.front();
            q.pop();
            sizee--;
            return popped;
        }
        return -1;
    }

    int top() {
        if(!q.empty()) return q.front();
        return -1;
    }
};