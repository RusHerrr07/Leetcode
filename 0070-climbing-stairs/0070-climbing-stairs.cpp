
class Solution {
    vector<int> dp;
    
    int countWays(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = countWays(n - 1) + countWays(n - 2);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        dp.assign(n + 1, -1);
        return countWays(n);
    }
};
