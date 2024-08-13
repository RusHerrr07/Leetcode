class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<set<vector<int>>> dp_arr(target+1);
        dp_arr[0] = {{}};

        for(int num: candidates){
            for(int i=target; i>=num; i--){
                for(vector<int> arr: dp_arr[i-num]){
                    arr.push_back(num);
                    dp_arr[i].insert(arr);
                }
            }
        }

        return  vector<vector<int>>(dp_arr[target].begin(), dp_arr[target].end());
    }
};