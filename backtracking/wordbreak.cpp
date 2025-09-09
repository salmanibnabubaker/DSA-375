void wordSplit(int index,vector<string>&dict,string &s,vector<string>&curr,vector<string>&wordSplits){
    if(index==s.length()){
        string res="";
        for(int i=0;i<curr.size()-1;i++){
            res+=(curr[i]+" ");
        }
        res+=curr[curr.size()-1];
        wordSplits.push_back(res);
        return;
    }
    for(int i=0;i<dict.size();i++){
        if(index+dict[i].length()-1<s.length()&&s.substr(index,dict[i].length())==dict[i]){
            curr.push_back(dict[i]);
            wordSplit(index+dict[i].length(),dict,s,curr,wordSplits);
            curr.pop_back();
        }
    }
    return;
}
vector<string> wordBreak(vector<string>& dict, string& s) {
    // code here
    vector<string>curr;
    vector<string>wordSplits;
    wordSplit(0,dict,s,curr,wordSplits);
    return wordSplits;
}