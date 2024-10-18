class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(auto &i:nums)
        {
            sum+=i;
            if(sum<i)
            {
                sum=i;
            }
            
            maxi=max(sum,maxi);
           
            
        }

        return maxi;
        
    }
};