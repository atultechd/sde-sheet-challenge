

bool is_possible(int n, int m, vector<int> time, long long mid){

    int days = 1;
    long long int req_time = 0;

    for(int i=0; i<m; i++){

        if(req_time + time[i] <= mid) {
          req_time += time[i];
        }

        else{
            days++;
            if(time[i] > mid || days > n){
                return false;
            }
            req_time = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time){        
    long long start = 0, total_time = 0;

    for(int i=0; i<time.size(); i++){
        total_time += time[i];
    }

    long long end = total_time;
    long long ans = -1;

    while(start <= end){

        long long mid = start + (end-start)/2;

        if(is_possible(n,m,time,mid)){

            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}