class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            int j;
            for(j=i+1;j<nums.size();j++)
            {
                if((temp&nums[j])!=0)
                {
                    break;
                }
                else
                {
                    temp=temp|nums[j];
                }
            }
            ans=max(ans,j-i);
        }    
        return ans;
    }
};