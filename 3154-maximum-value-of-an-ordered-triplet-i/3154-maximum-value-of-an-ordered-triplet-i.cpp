class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        int n = nums.size();
        vector<long long> pref(n, 0);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], (long long)nums[i]);
        }

        vector<long long> suff(n, 0);
        suff[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max((long long)nums[i], suff[i + 1]);
        }

        vector<int> nextSmaller(n, n);  
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextSmaller[i] = st.top();  
            }
            st.push(i);
        }

        for (int i = 0; i < n - 2; i++) {  
            long long val = pref[i];

            int idx = nextSmaller[i];  
            if (idx == n || idx + 1 >= n) continue;

            long long x = (val - nums[idx]) * suff[idx + 1];
            maxi = max(maxi, x);
        }

        return max(0LL, maxi);
    }
};
