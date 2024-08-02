class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    if(matrix[i][j]=='1')
                    {
                      dp[i][j]=1;
                    } 
                }
                else 
                    {
                        if(matrix[i][j]=='1')
                        {
                             dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                        }
                       
                    }
                     ans=max(ans,dp[i][j]);
            }
        }

        return ans*ans;
        
        
        
    }
};