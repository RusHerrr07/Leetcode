class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=1;
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi)cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }

        return ans;
       
    }
};