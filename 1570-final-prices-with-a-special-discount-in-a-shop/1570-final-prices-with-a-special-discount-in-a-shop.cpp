class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans(n,0);
    ans[n-1]=nums[n-1];
    for(int i=0;i<n;i++){
        ans[i]=nums[i];
        for(int j=i+1;j<n;j++){
            if(nums[i]>=nums[j]){
                ans[i]=nums[i]-nums[j];
                break;
            }
        }
    }
    return ans;
        
    }
};
