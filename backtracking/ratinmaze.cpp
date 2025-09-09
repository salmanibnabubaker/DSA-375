void findpath(int i,int j,int n,vector<vector<int>>&maze,vector<vector<int>>&vis,vector<char>&currPath,vector<string>&path){
    if(i<0||j<0||i==n||j==n){
        return;
    }
    if(vis[i][j]==1||maze[i][j]==0){
        return;
    }
    if(i==n-1&&j==n-1){
        string res="";
        for(int k=0;k<currPath.size();k++){
            res+=currPath[k];
        }
        path.push_back(res);
        return;
    }
    vis[i][j]=1;
    
    
    currPath.push_back('D');
    findpath(i+1,j,n,maze,vis,currPath,path);
    currPath.pop_back();
    
    
    currPath.push_back('L');
    findpath(i,j-1,n,maze,vis,currPath,path);
    currPath.pop_back();
    
    
    currPath.push_back('R');
    findpath(i,j+1,n,maze,vis,currPath,path);
    currPath.pop_back();
    
    
    currPath.push_back('U');
    findpath(i-1,j,n,maze,vis,currPath,path);
    currPath.pop_back();
    
    
    
    vis[i][j]=0;
    return;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    // code here
    int n=maze.size();
    vector<vector<int>>vis(n,vector<int>(n,0));
    vector<char>currPath;
    vector<string>path;
    findpath(0,0,n,maze,vis,currPath,path);
    return path;
}