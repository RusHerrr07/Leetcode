class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        int val=1;
        while(st.find(val)!=st.end())val++;
        return val;
        
    }
};