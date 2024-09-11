class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int i=0,j=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]>nums[i]){
                ans+=(j-i)*(long long)nums[i];
                i=j;
            }
            j++;
            if(j==n-1){
                ans+=(j-i)*(long long)nums[i];
                break;

            }
        }
        return ans;
        
    }
};