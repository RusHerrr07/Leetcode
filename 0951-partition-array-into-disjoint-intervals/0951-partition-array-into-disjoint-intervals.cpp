class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int left=nums[0];
        int maxi=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(left>nums[i]){
                ans=i;
                left=maxi;
            }
            maxi=max(maxi,nums[i]);
        }
        return ans+1;
        
    }
};