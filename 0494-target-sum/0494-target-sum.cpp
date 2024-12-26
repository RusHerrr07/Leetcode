/*

class Solution {
   
    int cnt=0;
private:
void solve(vector<int>&nums,int idx,int n,int target,int sum){
    if(idx==n){
    if(target==sum){
      cnt++;
    }
    return;
}
   
    solve(nums,idx+1,n,target,sum+nums[idx]);
    solve(nums,idx+1,n,target,sum-nums[idx]);
    
    
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    
 solve(nums,0,nums.size(),target,0);
 return cnt;
        
    }
};



*/





// optimization with sonal madam->dp;

class Solution {
    int sonal[20+2][2000+2];
    int solve(vector<int>& nums,int idx,int target,int sum) {
        if (idx==nums.size()) { 
            if(sum==target)return 1;
            else return 0;
        }
        if (sonal[idx][sum+1000]!=-1) {
            return sonal[idx][sum+1000];
        }
        int ans1 =solve(nums,idx +1,target,sum+nums[idx]);
        int ans2 =solve(nums,idx+1,target,sum -nums[idx]);
        return sonal[idx][sum+1000] = ans1+ans2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(sonal,-1,sizeof(sonal));
        return solve(nums,0,target,0);
    }
};
