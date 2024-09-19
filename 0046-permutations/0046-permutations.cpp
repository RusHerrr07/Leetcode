
class Solution {
    long long factorial(int n) {
        if (n < 0) return 0;

        std::vector<long long> dp(n + 1, 1);

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] * i;
        }

        return dp[n];
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        long long fact = factorial(n);

        std::sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return ans;
    }
};
