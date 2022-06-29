// Stack class.
class Stack {
    int *arr;
    int ind;
    int size;
public:
    Stack(int capacity) {
        size = capacity;
        arr = new int[size];
        ind = -1;
    }

    void push(int num) {
        if(ind<size-1) arr[++ind] = num;
    }

    int pop() {
        if(ind != -1) return arr[ind--];
        else return -1;
    }
    
    int top() {
        if(ind != -1 && ind < size) return arr[ind];
        else return -1;
    }
    
    int isEmpty() {
        if(ind == -1)return 1;
        else return 0;
    }
    
    int isFull() {
        if(ind >= size) return 1;
        else return 0;
    }
    
};