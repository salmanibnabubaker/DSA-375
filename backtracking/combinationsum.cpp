void findSum(int sum,int i,vector<int>&arr,vector<int>&curr,vector<vector<int>>&combs){
    if(sum<0){
        return;
    }
    if(sum==0){
        combs.push_back(curr);
        return;
    }
    for(int j=i;j<arr.size();j++){
        curr.push_back(arr[j]);
        findSum(sum-arr[j],j,arr,curr,combs);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int> &arr, int target) {
    // Your code here
    vector<int>curr;
    vector<vector<int>>combs;
    for(int i=0;i<arr.size();i++){
        curr.push_back(arr[i]);
        findSum(target-arr[i],i,arr,curr,combs);
        curr.pop_back();
    }
    return combs;
}