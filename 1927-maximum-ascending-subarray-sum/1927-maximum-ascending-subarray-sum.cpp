class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i=1;
        if(n==1)return nums[0];
        while(i<n){
           int sum=nums[i-1];
           if(nums[i]>nums[i-1]){
             while(i<n && nums[i-1]<nums[i]){
               sum+=nums[i];
               i++;
             }
            }
            else{
                sum=nums[i-1];
                i++;
            }

            ans=max(ans,sum);
            
          

        }
        return ans;
        
    }
};