class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int in=1,dec=1,n=nums.size(),i=0, maxi=0;
        if(nums.size()==1) return 1;
        while(i<n-1){
            
            if(nums[i]<nums[i+1])
            {
                in++;
                dec=1;
            }
            else if( nums[i]>nums[i+1])
            {
                dec++;
                in=1;
            }
            else in=dec=1;
            maxi=max(maxi,max(in,dec));
            i++;

        }

        return maxi;
        
    }
};