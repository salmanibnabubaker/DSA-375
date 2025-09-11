int increasinglength(int index,int prev,vector<int>&arr,vector<int>&memo){
    if(prev>=arr[index]){
        return 0;
    }
    if(memo[index]!=0){
        return memo[index];
    }
    int maxlength=0;
    for(int i=index+1;i<arr.size();i++){
        maxlength=max(maxlength,increasinglength(i,arr[index],arr,memo));
    }
    memo[index]=maxlength+1;
    return memo[index];
}
int lis(vector<int>& arr) {
    // code here
    vector<int>memo(arr.size(),0);
    int maxlen=0;
    for(int i=0;i<arr.size();i++){
        maxlen=max(maxlen,increasinglength(i,-1,arr,memo));
    }
    return maxlen;
}