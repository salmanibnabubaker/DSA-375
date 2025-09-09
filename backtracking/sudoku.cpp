//function to find empty cells to be filled
vector<vector<int>> emptycells(vector<vector<int>>&mat){
    vector<vector<int>>cells;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==0){
                cells.push_back({i,j});
            }
        }
    }
    return cells;
}
vector<vector<int>> findblockindexes(int i,int j){
    if(i<=2){
        if(j<=2){
            return {{0,0},{2,2}};
        }
        else if(j<=5){
            return {{0,3},{2,5}};
        }
        else{
            return {{0,6},{2,8}};
        }
    }
    else if(i<=5){
        if(j<=2){
            return {{3,0},{5,2}};
        }
        else if(j<=5){
            return {{3,3},{5,5}};
        }
        else{
            return {{3,6},{5,8}};
        }
    }
    else{
        if(j<=2){
            return {{6,0},{8,2}};
        }
        else if(j<=5){
            return {{6,3},{8,5}};
        }
        else{
            return {{6,6},{8,8}};
        }
    }
}
//checks num can be filled
bool canfill(int i,int j,int num,vector<vector<int>>&mat){
    
    //column check
    for(int k=0;k<9;k++){
        if(mat[k][j]==num){
            return false;
        }
    }
    
    //row check
    for(int k=0;k<9;k++){
        if(mat[i][k]==num){
            return false;
        }
    }
    
    
    //block check
    vector<vector<int>>bound=findblockindexes(i,j);
    for(int k=bound[0][0];k<=bound[1][0];k++){
        for(int l=bound[0][1];l<=bound[1][1];l++){
            if(mat[k][l]==num){
                return false;
            }
        }
    }
    
    return true;
}
//recursive function to fill sudoku
bool fillsudoku(int i,vector<vector<int>>&mat,vector<vector<int>>&emptycells){
    if(i==emptycells.size()){
        return true;
    }
    for(int j=1;j<=9;j++){
        if(canfill(emptycells[i][0],emptycells[i][1],j,mat)){
            mat[emptycells[i][0]][emptycells[i][1]]=j;
            if(fillsudoku(i+1,mat,emptycells)){
                return true;
            }
            mat[emptycells[i][0]][emptycells[i][1]]=0;
        }
    }
    return false;
}

// Function to find a solved Sudoku.
void solveSudoku(vector<vector<int>> &mat) {
    // code here
    vector<vector<int>>cells=emptycells(mat);
    bool possible=fillsudoku(0,mat,cells);
}