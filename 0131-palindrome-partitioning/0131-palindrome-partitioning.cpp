class Solution {
bool isPalindrome(string &s,int i,int j){
    int n=s.size();
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
vector<vector<string>>ans;
vector<string>str;
void solve(string &s,int idx,int n){
    if(idx==n){
        ans.push_back(str);
        return ;
    }
    
    for(int i=idx;i<s.size();i++){
        if(isPalindrome(s,idx,i)){
            string temp=s.substr(idx,i-idx+1);
            str.push_back(temp);
            solve(s,i+1,n);
            str.pop_back();


        }
    }

}

public:
    vector<vector<string>> partition(string s) {
         solve(s,0,s.size());
         return ans;
        
    }
};