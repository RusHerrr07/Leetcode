class Solution {
int dp[501][501];
int solve(string &s,string &t,int i,int j,int n,int m){
    if (i==n) return m-j;
    if (j==m) return n-i;
    if(dp[i][j]!=-1)return dp[i][j];
    // if(i>=n || j>=m)return 1e9;
    if(s[i]==t[j]){
       dp[i][j]= solve(s,t,i+1,j+1,n,m);
    }
    else{
        int remove1=1+solve(s,t,i+1,j,n,m);
        int remove2=1+solve(s,t,i,j+1,n,m);
        dp[i][j]=min(remove1,remove2);
    }
    return dp[i][j];
}
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0,word1.size(),word2.size());
        
        
    }
};