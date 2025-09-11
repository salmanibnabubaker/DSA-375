void removereaches(int i,int j,int n,vector<vector<int>>&reached){
    int x,y;
    
    x=i-1;
    y=j-1;
    while(x>=0&&y>=0){
        reached[x][y]--;
        x--;
        y--;
    }
    
    
    x=i+1;
    y=j+1;
    while(x<n&&y<n){
        reached[x][y]--;
        x++;
        y++;
    }
    
    x=i-1;
    y=j+1;
    while(x>=0&&y<n){
        reached[x][y]--;
        x--;
        y++;
    }
    
    
    x=i+1;
    y=j-1;
    while(x<n&&y>=0){
        reached[x][y]--;
        x++;
        y--;
    }
    
    for(int k=0;k<n;k++){
        if(k==i){
            continue;
        }
        reached[k][j]--;
    }
    for(int k=0;k<n;k++){
        if(k==j){
            continue;
        }
        reached[i][k]--;
    }
    
}
void addreaches(int i,int j,int n,vector<vector<int>>&reached){
    int x,y;
    
    x=i-1;
    y=j-1;
    while(x>=0&&y>=0){
        reached[x][y]++;
        x--;
        y--;
    }
    
    
    x=i+1;
    y=j+1;
    while(x<n&&y<n){
        reached[x][y]++;
        x++;
        y++;
    }
    
    x=i-1;
    y=j+1;
    while(x>=0&&y<n){
        reached[x][y]++;
        x--;
        y++;
    }
    
    
    x=i+1;
    y=j-1;
    while(x<n&&y>=0){
        reached[x][y]++;
        x++;
        y--;
    }
    
    for(int k=0;k<n;k++){
        if(k==i){
            continue;
        }
        reached[k][j]++;
    }
    for(int k=0;k<n;k++){
        if(k==j){
            continue;
        }
        reached[i][k]++;
    }
    
}
void placequeens(int index,int n,vector<vector<int>>&board,vector<vector<int>>&reached,vector<vector<int>>&pos){
    if(index==n-1){
        vector<int>row;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(board[i][j]==1){
                    row.push_back(i+1);
                    break;
                }
            }
        }
        pos.push_back(row);
        return;
    }
    for(int i=0;i<n;i++){
        if(reached[i][index]==0&&board[i][index]==0){
            board[i][index]=1;
            addreaches(i,index,n,reached);
            placequeens(index+1,n,board,reached,pos);
            board[i][index]=0;
            removereaches(i,index,n,reached);
        }
    }
    return;
}
vector<vector<int>> nQueen(int n) {
    // code here
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>reached(n,vector<int>(n,0));
    vector<vector<int>>pos;
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=1;
            addreaches(i,j,n,reached);
            placequeens(0,n,board,reached,pos);
            board[i][j]=0;
            removereaches(i,j,n,reached);
        }
    }
    
    return pos;
}