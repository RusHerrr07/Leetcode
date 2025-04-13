class Solution {
vector<int>dp;
private:
    bool solve(vector<int>& arr, int idx, int n) {
        if (idx < 0 || idx >= n || arr[idx] < 0) return false;
        if (arr[idx] == 0) return true;
        
        int jump = arr[idx];
        arr[idx] = -arr[idx]; 
        if(dp[idx]!=-1)return dp[idx];
        
        bool aage = solve(arr, idx + jump, n);
        bool piche = solve(arr, idx - jump, n);
        return  dp[idx]=aage || piche;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        dp.assign(arr.size(),-1);
        return solve(arr, start, arr.size());
    }
};
