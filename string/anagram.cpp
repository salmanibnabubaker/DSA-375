bool isAnagram(string s, string t) {
    if(s.length()!=t.length()){
        return false;
    }
    int hash1[26]={},hash2[26]={};
    for(int i=0;i<s.length();i++){
        int ch=s[i];
        hash1[ch-97]++;
    }
    for(int i=0;i<t.length();i++){
        int ch=t[i];
        hash2[ch-97]++;
    }
    for(int i=0;i<26;i++){
        if(hash1[i]!=hash2[i]){
            return false;
        }
    }
    return true;
}