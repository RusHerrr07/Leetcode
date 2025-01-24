/*
class Solution {
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m, int sum, int k) {
        if (i==n-1&&j==m-1) return(sum+grid[i][j])%k==0?1:0;
        if (i>=n||j>=m) return 0;

        sum += grid[i][j];
        int right=solve(grid,i+1,j,n,m,sum,k);
        int down=solve(grid,i,j+1,n,m,sum,k);
        return right + down;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        return solve(grid, 0, 0, n, m, 0, k);
    }
};

*/

//Aaajao Dp and mathematics(modular maths) ki help   se isko optimize kreee->

class Solution {
    int n,m,k;
    int solve(vector<vector<int>>& grid,int i,int j,int mod,vector<vector<vector<int>>>& dp) {
        if(i==n-1 && j==m-1)return(mod+grid[i][j])%k==0;
        if(i>=n || j>=m)return 0;
        if(dp[i][j][mod]!=-1)return dp[i][j][mod];
        int newMod=(mod+grid[i][j])%k;
        int ans=0;
        int right=solve(grid,i+1,j,newMod,dp)%(int)(1e9+7);
        int down=solve(grid,i,j+1,newMod,dp)%(int)(1e9+7);
        return dp[i][j][mod]=(right +down)%(int)(1e9+7);;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid,int K) {
        n=grid.size(),m=grid[0].size(),k=K;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return solve(grid,0,0,0,dp);
    }
};
