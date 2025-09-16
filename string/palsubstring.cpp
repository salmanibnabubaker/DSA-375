string longestPalindrome(string S){
    // code here 
    int max=0;
    int len=0;
    string x;
    string y;
    string a;
    string result;
    for(int i=0;i<S.length();i++){
        x="";
        y="";
        for(int j=i;j<S.length();j++){
            a=S.at(j);
            x=x+a;
            y=a+y;
            
            
            if(x==y){
                len=x.length();
                if(len>max){
                    max=len;
                    result=x;
                }
            }
        }
    }
    
    return result;
}