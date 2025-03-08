class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        
        int k=1;
        int sum=0;
        int j=0;
        int i=0;
        int n=nums.size();
        int maxi=0;
       
        while(j<n){
            sum+=nums[j];
            while((j-i+1)-sum>k){
                sum-=nums[i];
                i++;
            }
            maxi=max(j-i,maxi);
            j++;

        }
        return maxi;
        
    }
};