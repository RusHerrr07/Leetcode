class Solution {
vector<int>dp;
 int solve(vector<int>& arr, int idx, int n) {
    if(idx>=n)return 1e9;
        if(idx >= n-1) return 0;
        if(dp[idx] != -1) return dp[idx];

        int steps = 1e9;
        int val = arr[idx];
        for(int i=1; i<=val; i++) {
            steps = min(steps, 1 + solve(arr, idx + i, n));
        }
        return dp[idx] = steps;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        // if(nums[0]==0)return 
        // int cnt=1;
        // int val=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     val--;
        //     if(i+val>=n-1)return cnt;
        //     if(nums[i]>val){
        //         val=nums[i];
        //         cnt++;
        //     }

        // }
        // return cnt;

        dp.assign(n,-1);
        return solve(nums,0,n);
    
    }
};