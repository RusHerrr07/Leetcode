
class Solution {
int dp[101][101];
int solve(int i,int j,int n,int m){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 ||j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=solve(i-1,j,n,m);
    int left=solve(i,j-1,n,m);
    dp[i][j]=up+left;
    return dp[i][j];
}
public:

    int uniquePaths(int m, int n) {
        int i=m-1;
        int j=n-1;
        memset(dp,-1,sizeof(dp));
        return solve(i,j,m,n);
        
    }
};