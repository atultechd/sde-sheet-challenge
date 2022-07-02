vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> res;
    int n = nums.size();
    for(int i=0; i<=n-k; i++){
        int max = nums[i];
        for(int j=1; j<k; j++){
            if(nums[i+j] > max) max = nums[i+j];
        }
        res.push_back(max);
    }
    return res;
}