class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int ohk = 0;
        for (int i = 1; i < n; ++i) {
            if (i >= minJump) {
                ohk += dp[i - minJump];
                }
            if (i > maxJump) {
                ohk -= dp[i - maxJump - 1];
                }
            dp[i] = (s[i] == '0' && ohk > 0);
        }
        return dp[n - 1];
    }
};