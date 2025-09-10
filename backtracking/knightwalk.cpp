int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    // Code here
    vector<vector<int>>vis(N,vector<int>(N,0));
    queue<pair<int,int>>index;
    index.push({KnightPos[0]-1,KnightPos[1]-1});
    vis[KnightPos[0]-1][KnightPos[1]-1]=1;
    int moves=0;
    while(!index.empty()){
        int sz=index.size();
        for(int k=0;k<sz;k++){
            int i=index.front().first;
            int j=index.front().second;
            index.pop();
            if(i==TargetPos[0]-1&&j==TargetPos[1]-1){
                return moves;
            }
            
            if(i-2>=0&&j+1<N&&vis[i-2][j+1]==0){
                index.push({i-2,j+1});
                vis[i-2][j+1]=1;
            }
            if(i-1>=0&&j+2<N&&vis[i-1][j+2]==0){
                index.push({i-1,j+2});
                vis[i-1][j+2]=1;
            }
            if(i+1<N&&j+2<N&&vis[i+1][j+2]==0){
                index.push({i+1,j+2});
                vis[i+1][j+2]=1;
            }
            if(i+2<N&&j+1<N&&vis[i+2][j+1]==0){
                index.push({i+2,j+1});
                vis[i+2][j+1]=1;
            }
            
            if(i+2<N&&j-1>=0&&vis[i+2][j-1]==0){
                index.push({i+2,j-1});
                vis[i+2][j-1]=1;
            }
            if(i+1<N&&j-2>=0&&vis[i+1][j-2]==0){
                index.push({i+1,j-2});
                vis[i+1][j-2]=1;
            }
            if(i-1>=0&&j-2>=0&&vis[i-1][j-2]==0){
                index.push({i-1,j-2});
                vis[i-1][j-2]=1;
            }
            if(i-2>=0&&j-1>=0&&vis[i-2][j-1]==0){
                index.push({i-2,j-1});
                vis[i-2][j-1]=1;
            }
        }
        
        moves++;
    }
    
    return -1;
}