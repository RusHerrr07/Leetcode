class Solution {
int dp[101][101];
int solve(vector<vector<int>>&grid,int i,int j,int n,int m){
	if(i==n-1 && j==m-1 && grid[i][j]!=1){
		return 1;
	}
	if(i>=n || j>=m || grid[i][j]==1)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int down =solve(grid,i+1,j,n,m);
	int right=solve(grid,i,j+1,n,m);
	dp[i][j]=down+right;
	return dp[i][j];
}


public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        int ans=solve(grid,0,0,n,m);
	// cout<<ans;
    return ans;

    }
};