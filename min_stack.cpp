#include<bits/stdc++.h>
class minStack{
    int sizee;
    int topp;
    int *mini;
    int *arr;
  public:
    
    // Constructor
    minStack() { 
            sizee = 1e6 + 1;
            topp = -1;
            mini = new int[sizee];
            arr = new int[sizee];
        }
    
        // Function to add another element equal to num at the top of stack.
        void push(int num){
            topp++;
            arr[topp] = num;
            if(topp==0) mini[topp] = num;
            else mini[topp] = min(mini[topp-1],num);
    }
        
    // Function to remove the top element of the stack.
    int pop(){
            if(topp == -1) return -1;
            else return arr[topp--];
    }
    
    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top(){
            if(topp == -1) return -1;
            else return arr[topp];
    }
    
    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin(){
            return topp==-1 ? -1 : mini[topp];
    }
};