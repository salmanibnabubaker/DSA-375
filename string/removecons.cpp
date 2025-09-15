string removeConsecutiveCharacter(string& s) {
    // code here.
    string res="";
    char prev='0';
    for(int i=0;i<s.length();i++){
        if(s[i]!=prev){
            prev=s[i];
            res+=s[i];
        }
    }
    return res;
}