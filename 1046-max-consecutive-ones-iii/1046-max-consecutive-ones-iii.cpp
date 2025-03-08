class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

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
            maxi=max(j-i+1,maxi);
            j++;

        }
        return maxi;
       
        
        
    }
};