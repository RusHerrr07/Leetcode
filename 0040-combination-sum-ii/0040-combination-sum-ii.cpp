class Solution {
    vector<vector<int>> ans;

    void solve(vector<int>& arr, vector<int>& temp, int target, int idx) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < arr.size(); i++) {
            if(i > idx && arr[i] == arr[i - 1]) continue;
            if(arr[i] > target) break;

            temp.push_back(arr[i]);
            solve(arr, temp, target - arr[i], i + 1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, temp, target, 0);
        return ans;
    }
};
