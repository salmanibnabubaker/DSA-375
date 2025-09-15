int lengthOfLongestSubstring(string s) {
    if(s.length()==0){
        return 0;
    }
    unordered_map<char,int>hash;
    //hash.insert({s[0],0});
    hash[s[0]]=0;
    int left=0,len=0;
    for(int i=1;i<s.length();i++){
        //previously occured
        if(hash.find(s[i])!=hash.end()){
            left=max(hash[s[i]]+1,left);
        }
        hash[s[i]]=i;
        if(i-left+1>len){
            len=i-left+1;
        }
    }
    return len;
}