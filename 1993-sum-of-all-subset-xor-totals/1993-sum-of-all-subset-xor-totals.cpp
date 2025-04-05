// class Solution {
// private:
// int solve(vector<int>&nums,int i,int n,int val){
//     if(i==n)return val;
//     int value=nums[i];
//     int take=solve(nums,i+1,n,val^value);
//     int not_Take=solve(nums,i+1,n,val);
//     return take+not_Take;
// }
// public:
//     int subsetXORSum(vector<int>& nums) {
//         // vector<vector<int>> res;
//         // vector<int> path;
//         // dfs(0, nums, path, res);

//         // int sum = 0;
//         // for (auto& subset : res) {
//         //     int xorSum = 0;
//         //     for (int val : subset) {
//         //         xorSum ^= val;
//         //     }
//         //     sum += xorSum;
//         // }

//         // return sum;

//         return solve(nums,0,nums.size(),0);
//     }

// private:
//     void dfs(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
//         if (i == nums.size()) {
//             res.push_back(path);
//             return;
//         }
//         path.push_back(nums[i]);
//         dfs(i + 1, nums, path, res); 
//         path.pop_back();
//         dfs(i + 1, nums, path, res);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> path;
//         dfs(0, nums, path, res);
//         return res;
//     }
// };




class Solution {
    int dp[15][1025]; 

    int solve(vector<int>& a, int i, int x) {
        if (i == a.size()) return x;
        if (dp[i][x] != -1) return dp[i][x];

        int take = solve(a, i + 1, x ^ a[i]);
        int notTake = solve(a, i + 1, x);
        return dp[i][x] = take + notTake;
    }

public:
    int subsetXORSum(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        return solve(a, 0, 0);
    }
};
