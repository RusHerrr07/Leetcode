class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }

        vector<int> suff1(n, 1e9);
        vector<int> suff2(n, 0);
        suff1[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suff1[i] = min(nums[i], suff1[i + 1]);
        }

        suff2[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff2[i] = max(nums[i], suff2[i + 1]);
        }

        for (int i = 1; i < n - 1; i++) {
            // long long val = long(pref[i-1]-nums[i])*suff2[i+1];
            maxi = max(maxi, (1LL * (pref[i-1] - nums[i]) * suff2[i+1]));

        }

        return maxi < 0 ? 0 : maxi;
    }
};