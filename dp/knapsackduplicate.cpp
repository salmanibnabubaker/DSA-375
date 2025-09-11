// TLE 1110/1111 test case passed
// need to optimize


int maxprofit(int index,int capacity,vector<int>&value,vector<int>&weight,vector<vector<int>>&memo){
    if(capacity<0){
        return 0;
    }
    if(capacity==0){
        return value[index];
    }
    if(memo[index][capacity]!=-1){
        return memo[index][capacity];
    }
    int profit=0;
    for(int i=0;i<value.size();i++){
        profit=max(profit,maxprofit(i,capacity-weight[i],value,weight,memo));
    }
    memo[index][capacity]=value[index]+profit;
    return memo[index][capacity];
}
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    int profit=0;
    vector<vector<int>>memo(val.size(),vector<int>(capacity,-1));
    for(int i=0;i<val.size();i++){
        profit=max(profit,maxprofit(i,capacity-wt[i],val,wt,memo));
    }
    return profit;
}