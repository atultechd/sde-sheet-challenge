string writeAsYouSpeak(int n) {
    string res = "1";
    for(int i=1; i<n; i++){
        string temp = "";
        int count = 1;
        for(int j=0; j<res.length()-1; j++){
            if(res[j] == res[j+1]) count++;
            else{
                temp += (to_string(count) + res[j]);
                count = 1;
            }
        }
        temp += to_string(count) + res[res.length()-1];
        res = temp;
    }
    return res;
}