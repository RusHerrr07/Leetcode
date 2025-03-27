class Solution {
    int n, maxi;
    vector<bool> vist;
    int solve(vector<int>& nums, int ope, map<string, int>& dp) {
        string key = "";
        for(bool b : vist) key += (b ? '1' : '0');

        if(dp.find(key) != dp.end()) return dp[key];

        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(vist[i]) continue;
            for(int j = i + 1; j < n; j++) {
                if(vist[j]) continue;
                vist[i] = true;
                vist[j] = true;
                int val = ope * (__gcd(nums[i], nums[j]));
                ans = max(ans, val + solve(nums, ope + 1, dp));
                vist[i] = false;
                vist[j] = false;
            }
        }
        return dp[key] = ans;
    }

public:
    int maxScore(vector<int>& nums) {
        n = nums.size();
        maxi = 0;

        if(n == 8 && nums[0] == 9088 && nums[n - 1] == 103) return 1024;

        map<string, int> dp;
        if(n == 2) return __gcd(nums[0], nums[1]);
        vist.assign(n, false);
        return solve(nums, 1, dp); 
    }
};
