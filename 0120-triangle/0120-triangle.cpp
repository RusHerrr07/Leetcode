class Solution {

int dp[201][201];
    
int solve(vector<vector<int>>& triangle, int i, int j, int n, int m) {
    if (i == n - 1) {
        return triangle[i][j];
    }
    if (i >= n ) {
        return INT_MAX;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int first = INT_MAX, sec = INT_MAX;
    
        first = solve(triangle, i + 1, j + 1, n, m);
    
    sec = solve(triangle, i + 1, j, n, m);
    dp[i][j] = min(first, sec)+triangle[i][j];
    return dp[i][j];
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*

        how greedy failed in this problem, just look at there--->





        int ans = triangle[0][0], n = triangle.size(), i = 0, j = 0;
        while (i + 1 < n) {
            int first = INT_MAX, sec = INT_MAX;
            if (i + 1 < n) {
                sec = triangle[i + 1][j];
                if (j + 1 < triangle[i + 1].size()) {
                    first = triangle[i + 1][j + 1];
                }
            }
            if (first < sec) {
                ans += first;
                i++;
                j++;
            } else {
                ans += sec;
                i++;
            }
        }
        return ans;

        */


        // now let's try dp with memoization-->

        int n = triangle.size();
        int m = triangle[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(triangle, 0, 0, n, m);

    


    }
};
