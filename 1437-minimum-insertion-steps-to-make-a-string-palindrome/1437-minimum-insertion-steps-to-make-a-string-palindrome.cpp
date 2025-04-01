class Solution {
int dp[500+1][500+1];
int solve(string &s,int i,int j,int n){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j]){
       dp[i][j]= solve(s,i+1,j-1,n);
    }
    else{
        int left=1+solve(s,i+1,j,n);
        int right=1+solve(s,i,j-1,n);
        dp[i][j]=min(left,right);

    }
    return dp[i][j];

}
public:
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1,n);
    }
};