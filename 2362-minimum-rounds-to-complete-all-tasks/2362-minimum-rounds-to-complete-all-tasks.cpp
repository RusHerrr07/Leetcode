class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for (auto& i : tasks) {
            mp[i]++;
        }

        int ans = 0;
        for (auto& i : mp) {
            int freq = i.second;
            if (freq < 2) {
                return -1;
            }

            if (freq % 3 == 0) {
                ans += freq / 3;
            } else {
                ans += freq / 3 + 1;
            }
        }

        return ans;
    }
};
