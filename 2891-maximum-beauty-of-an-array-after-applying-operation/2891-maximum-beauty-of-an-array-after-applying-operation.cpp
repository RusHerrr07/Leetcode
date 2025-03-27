class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> p;
        for (auto &i : nums) {
            p.push_back({i - k, i + k});
        }
        vector<int> start, end;
        for (auto &[fir, sec] : p) {
            start.push_back(fir);
            end.push_back(sec);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int maxi = 0;
        for (int i = 0; i < start.size(); i++) {
            int val = end[i];
            int idx = upper_bound(start.begin(), start.end(), val) - start.begin();
            // if(start[idx]==val){
            //     maxi=max(maxi,idx-i);
            // }
            idx -= 1;
            maxi = max(maxi, idx - i + 1);
        }
        return maxi;
    }
};
