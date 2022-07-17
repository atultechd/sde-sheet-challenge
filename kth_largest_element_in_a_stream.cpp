#include<bits/stdc++.h>
class Kthlargest {
public:
//     minheap bana rhe hain
    priority_queue<int, vector<int>, greater<int>> q;

//     mazze ki baat (arr) ka size (k) ke equal hai (k == arr.size).
    Kthlargest(int k, vector<int> &arr) {

       for(int i=0; i<k; i++){

           q.push(arr[i]);

       }
    }

//     chota element hai agar tou kya faida minheap me daalne ka.
//     aur agar (num > q.top()) tou insert krdo.
    void add(int num) {

        if(num <= q.top()) return;

        q.push(num);
        
        q.pop();
    }

//     minheap ka top hi tou hoga kth element kyonki ham k elements maintain krke chal rhe hain minheap me isliye.
    int getKthLargest() {

        return q.top();
        
    }

};