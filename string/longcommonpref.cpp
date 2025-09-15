string longestCommonPrefix(vector<string>& strs) {
    int minlength=INT_MAX;
    for(int i=0;i<strs.size();i++){
        if(strs[i].length()<minlength){
            minlength=strs[i].length();
        }
    }
    string res="";
    for(int i=0;i<minlength;i++){
        char x=strs[0][i];
        bool matched=true;
        for(int j=1;j<strs.size();j++){
            if(strs[j][i]!=x){
                matched=false;
                break;
            }
        }
        if(!matched){
            break;
        }
        res+=x;
    }
    return res;
}