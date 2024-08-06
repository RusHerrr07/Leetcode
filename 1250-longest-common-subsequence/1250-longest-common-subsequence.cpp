class Solution {
    int dp[1001][1001];
    int solve(int i, int j, int n, int m, string &text1, string &text2) {
        if (i >= n || j >= m) {
            return 0;
        }
        int ans1,ans2,ans3;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if (text1[i] == text2[j]) {
            dp[i][j]=1 + solve(i + 1, j + 1, n, m, text1, text2);
        } else {
             ans1 = solve(i + 1, j, n, m, text1, text2);
             ans2 = solve(i, j + 1, n, m, text1, text2);
             dp[i][j]= max(ans1,ans2);
             
        }
        return dp[i][j];
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, n, m, text1, text2);
    }
};
