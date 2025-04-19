class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int l=lower-nums[i];
            int r=upper-nums[i];
            int x=lower_bound(nums.begin()+i+1,nums.end(),l)-nums.begin();
            int y=upper_bound(nums.begin()+i+1,nums.end(),r)-nums.begin();
            ans+=y-x;
        }
        return ans;
    }
};
