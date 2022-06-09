#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n){
    long long total_sum = 0, current_sum = 0;
    for(int i=0; i<n; i++){
        current_sum += arr[i];
        if(current_sum > total_sum){
            total_sum = current_sum;
        }
        if(current_sum < 0){
            current_sum = 0;
        }
    }

    return total_sum;
}

// There is a test case which should be resolved 
// that if all the array elements are smaller than zero, so we have to return 
// larget among them but with this code we'll get zero
// so for that we need to check 

  // if(total_sum == 0){
  
      // for(int i=0; i<n; i++){
          // total_sum = max(total_sum, arr[i]);
      // }
  // }

  // return total_sum;


// The above code should be included before return statement of the given code.