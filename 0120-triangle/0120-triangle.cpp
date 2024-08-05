class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& triangle,int i,int j,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
      
        int first=solve(triangle,i+1,j,n)+triangle[i][j];;
        int sec=solve(triangle,i+1,j+1,n)+triangle[i][j];
        dp[i][j]=min(first,sec);
        return dp[i][j];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int n=triangle.size();
        return solve(triangle,0,0,n);
    }
};