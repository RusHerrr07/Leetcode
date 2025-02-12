class Solution {
bool isPalindrome(string &s,int i,int j){
    while(j>=i){
        if(s[i]!=s[j])return false;
        j--;
        i++;
    }
    return true;
}
public:
    string longestPalindrome(string s) {
        int maxi=0;
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
             if(isPalindrome(s,i,j)){
                if(j-i+1>maxi){
                    maxi=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
             }
            }
        }
        return ans;

        
    }
};