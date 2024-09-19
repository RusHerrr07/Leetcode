class Solution {
 
void solve(int n ,int open, int close, string s,vector<string>&ans){
    if(open == n && close ==n){
        ans.push_back(s);
        return;
    }

    if(open<n){
        solve(n,open+1 ,close,s+'(',ans);
    }
    if(close<open){
        solve(n ,open,close+1,s+')',ans);
    }

     }
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string>ans;
        solve(n,0,0,s,ans);
        return ans;    
    }
};