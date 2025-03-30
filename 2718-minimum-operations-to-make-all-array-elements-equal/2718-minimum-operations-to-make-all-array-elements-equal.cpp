class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<long long> ans, pref(n);
        sort(nums.begin(), nums.end());
        
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) 
            pref[i] = pref[i - 1] + nums[i];

        for (auto &val : queries) {
            int idx = lower_bound(nums.begin(), nums.end(), val) - nums.begin();
            long long left_sum = (idx > 0) ? pref[idx - 1] : 0;
            long long right_sum = pref[n - 1] - left_sum;
            long long left_ops = (long long) idx * val - left_sum;
            long long right_ops = right_sum - (long long) (n - idx) * val;
            ans.push_back(left_ops + right_ops);
        }
        
        return ans;
    }
};
