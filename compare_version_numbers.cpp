int compareVersions(string a, string b) {
    int i=0, j=0, len1 = a.size(), len2 =b.size();
    while (i < len1 || j < len2){
        long long n1 = 0, n2 = 0;
        while(i<len1 && a[i] != '.'){
            n1 = n1 * 10 + 1ll * (a[i] - '0');
            i++;
        }
        while(j<len2 && b[j] != '.'){
            n2 = n2 * 10 + 1ll * (b[j] - '0');
            j++;
        }
        if(n2 < n1) return 1;
        else if (n1 < n2) return -1;
        i++, j++;
    }
    return 0;
}