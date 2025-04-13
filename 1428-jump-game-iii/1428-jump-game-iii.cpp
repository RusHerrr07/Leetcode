class Solution {
private:
    bool solve(vector<int>& arr, int idx, int n) {
        if (idx < 0 || idx >= n || arr[idx] < 0) return false;
        if (arr[idx] == 0) return true;
        
        int jump = arr[idx];
        arr[idx] = -arr[idx]; 
        
        bool aage = solve(arr, idx + jump, n);
        bool piche = solve(arr, idx - jump, n);
        return aage || piche;
    }

public:
    bool canReach(vector<int>& arr, int start) {
        return solve(arr, start, arr.size());
    }
};
