
void solve(int index, int sum, vector<int> &num, vector<int> &res){
    if(index == num.size()){
        res.push_back(sum);
        return;
    }
    solve(index+1,sum+num[index],num,res);
    solve(index+1,sum,num,res);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    solve(0,0,num,res);
    sort(res.begin(),res.end());
    return res;
}