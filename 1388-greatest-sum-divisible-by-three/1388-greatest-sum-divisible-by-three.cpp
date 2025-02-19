class Solution {
long long dp[40000+1][3];
  int solve(vector<int>&nums,int i,int n,int x){
    if(i==n){
        if(x==0)return 0;
        else return -1e9;
    }
    if(dp[i][x]!=-1)return dp[i][x];
    int take=nums[i]+solve(nums,i+1,n,(nums[i]+x)%3);
    int not_take=solve(nums,i+1,n,x);
    return dp[i][x]=max(take,not_take);
    
  }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,n,0);

        
    }
};
