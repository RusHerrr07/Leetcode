class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefXor(n);
        vector<int> ans;
        
        prefXor[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefXor[i] = prefXor[i-1] ^ arr[i];
        }
        
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            if (left == 0) {
                ans.push_back(prefXor[right]);
            } else {
                ans.push_back(prefXor[right] ^ prefXor[left-1]);
            }
        }

        return ans;
    }
};
