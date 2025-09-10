bool issafe(int i,int j,vector<vector<int>>&mat){
    if(mat[i][j]==0||(i-1>=0&&mat[i-1][j]==0)||(i+1<mat.size()&&mat[i+1][j]==0)||(j-1>=0&&mat[i][j-1]==0)||(j+1<mat[0].size()&&mat[i][j+1]==0)){
        return false;
    }
    return true;
    
}
int shortestroute(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&memo,vector<vector<int>>&vis){
    if(i<0||j<0||i==mat.size()||!issafe(i,j,mat)){
        return INT_MAX;
    }
    if(j==mat[0].size()-1){
        return 1;
    }
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    if(vis[i][j]==1){
        return INT_MAX;
    }
    vis[i][j]=1;
    int up,down,left,right;
    up=shortestroute(i-1,j,mat,memo,vis);
    down=shortestroute(i+1,j,mat,memo,vis);
    left=shortestroute(i,j-1,mat,memo,vis);
    right=shortestroute(i,j+1,mat,memo,vis);
    int mindist=min({INT_MAX,up,down,left,right});
    if(mindist==INT_MAX){
        memo[i][j]=INT_MAX;
    }
    else{
        memo[i][j]=mindist+1;
    }
    return memo[i][j];
}
int findShortestPath(vector<vector<int>> &mat) {
    // code here
    int mindist=INT_MAX;
    vector<vector<int>>memo(mat.size(),vector<int>(mat[0].size(),-1));
    vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
    for(int i=0;i<mat.size();i++){
        mindist=min(mindist,shortestroute(i,0,mat,memo,vis));
    }
    if(mindist==INT_MAX){
        return -1;
    }
    return mindist;
}