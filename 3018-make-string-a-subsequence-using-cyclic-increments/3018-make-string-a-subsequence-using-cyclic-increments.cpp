class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int idx=0;
        int n=str1.size();
        if(n<str2.size()){
            return false;
        }
        for(int i=0;i<n;i++){
           char ch1=str1[i];
            char ch2=(ch1=='z')? 'a':(ch1+1);
            if(str2[idx]==ch1 || str2[idx]==ch2){
                idx++;
            }

            if(idx==str2.size()){
                return true;
            }
        }
        return false;
        
    }
};