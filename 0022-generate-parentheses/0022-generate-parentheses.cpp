class Solution {
vector<string>ans;

private:
    void solve(int n,int open,int close,string temp){
        if(open==n && close==n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            // temp+='(';
            solve(n,open+1,close,temp+'(');
        }
        if(close<open){
            // temp+=')';
            solve(n,open,close+1,temp+')');
        }
    }
  
public:
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;

        
    }
};