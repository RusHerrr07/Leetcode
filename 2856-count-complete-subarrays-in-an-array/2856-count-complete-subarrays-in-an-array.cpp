class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int k = st.size();
        int cnt = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            st.clear();
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                if (st.size() == k) cnt++;
            }
        }
        
        return cnt;
    }
};
