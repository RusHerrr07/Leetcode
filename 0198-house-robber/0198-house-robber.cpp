
class Solution {
    int dp[46];

    int solve(std::vector<int>& nums, int i, int n) {
        if (i >= n) {
            return 0; 
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int ans1 = nums[i] + solve(nums, i + 2, n);
        int ans2 = solve(nums, i + 1, n);
        dp[i] = std::max(ans1, ans2);

        return dp[i];
    }

public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }

        return dp[n-1];
    }
};
