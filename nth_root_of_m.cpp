// TC: O(nLog2(m * 10^8)) SC: O(1);
long double multiply(long double num, int n){
    long double ans = 1.0;
    for(int i=1; i<=n; i++){
        ans *= num;
    }
    return ans;
}

long double findNthRootOfM(int n, long long m) {
    long double low =1.0;
    long double high = m;
    long double esp = 1e-9;
    while((high-low) > esp){
        long double mid = (low+high)/2.0;
        if(multiply(mid,n) > m) high = mid;
        else low = mid;
    }
    return high;
}

// ....................................................

// second solution using inbuild function pow()
long double findNthRootOfM(int n, long long m) {
    return pow(m, 1.000000/n);
}
