class Solution {
    long long dp[100001][3];

    long long solve(vector<int>& nums, int i, int n, int prevpar, int x) {
        if (i >= n) return 0;
        int par = nums[i] % 2;
        if (dp[i][prevpar] != -1) return dp[i][prevpar];

        if (par == prevpar) {
            return dp[i][prevpar] = nums[i] + solve(nums, i + 1, n, par, x);
        } else {
            long long take = nums[i] + solve(nums, i + 1, n, par, x) - x;
            long long not_take = solve(nums, i + 1, n, prevpar, x);
            return dp[i][prevpar] = max(take, not_take);
        }
    }

public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        int parity = nums[0] % 2;
        memset(dp, -1, sizeof(dp));
        return nums[0] + solve(nums, 1, n, parity, x);
    }
};
