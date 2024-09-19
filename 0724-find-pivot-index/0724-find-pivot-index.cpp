class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        long long sum = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = nums[i] + pref[i - 1];
            sum += nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (sum - pref[i] == 0) {
                    return i;
                }
            } else {
                if (sum - pref[i] == pref[i - 1]) {
                    return i;
                }
            }
        }

        return -1;
    }
};
