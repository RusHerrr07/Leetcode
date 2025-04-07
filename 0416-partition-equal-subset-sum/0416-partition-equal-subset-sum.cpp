class Solution {
vector<vector<int>>dp;
bool solve(vector<int>&nums,int i,int n,int target){
    if(i>=n || target<0)return false;
    if(target==0){
        return true;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int lelo=solve(nums,i+1,n,target-nums[i]);
    int matLe=solve(nums,i+1,n,target);
    return dp[i][target]= lelo || matLe;
}
public:
    bool canPartition(vector<int>& nums) {

        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum&1)return false;
        int target=sum/2;
        dp.assign(nums.size(),vector<int>(target+4,-1));
        return solve(nums,0,nums.size(),target);

        
    }
};