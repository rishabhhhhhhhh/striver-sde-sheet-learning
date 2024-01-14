string findLCP(string & str1, string & str2) {
    int len = min(str1.length(), str2.length());
    int index = 0;
    while(index < len && str1[index] == str2[index])
        index++;
    if(index==0)return "";
    return str1.substr(0,index);
}
string longestCommonPrefix (string arr[], int N)
{
    string ans=arr[0];
    for(int i=1;i<N;i++) {
        ans = findLCP(ans, arr[i]);
        if(ans=="")return "-1";
    }
    return ans;
}