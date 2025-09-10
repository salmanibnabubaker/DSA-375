int operate(int x,int y,char op){
    if(op=='+'){
        return x+y;
    }
    else if(op=='-'){
        return x-y;
    }
    return x*y;
}
void combinations(int i,int x,char op,vector<int>&arr,vector<char>&combs,vector<char>&res,bool &found){
    if(found){
        return;
    }
    combs.push_back(op);
    if(i==arr.size()-1){
        if(operate(x,arr[i],op)%101==0){
            found=true;
            res=combs;
        }
        combs.pop_back();
        return;
    }
    
    
    combinations(i+1,operate(x,arr[i],op),'+',arr,combs,res,found);
    combinations(i+1,operate(x,arr[i],op),'-',arr,combs,res,found);
    combinations(i+1,operate(x,arr[i],op),'*',arr,combs,res,found);
    
    
    combs.pop_back();
    return;
}
string arithmeticExpressions(vector<int> arr) {
    vector<char>combs;
    vector<char>res;
    bool found=false;
    combinations(1,arr[0],'+',arr,combs,res,found);
    combinations(1,arr[0],'-',arr,combs,res,found);
    combinations(1,arr[0],'*',arr,combs,res,found);
    string expr=to_string(arr[0]);
    for(int i=1;i<arr.size();i++){
        expr+=res[i-1];
        expr+=to_string(arr[i]);
    }
    return expr;
}