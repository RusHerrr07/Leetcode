
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.empty()) return "";
        int n = votes[0].size();
        map<char, vector<int>> mp;
        for (char c : votes[0]) {
            mp[c] = vector<int>(n, 0);
        } for (auto &vote : votes) {
            for (int i = 0; i < n; ++i) {
                mp[vote[i]][i]++;
            }
        }vector<pair<char, vector<int>>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);
        string ans;
        for (auto &p : vec) {
            ans += p.first;
        }return ans;
    }

private:
    static bool cmp(const pair<char, vector<int>> &a, const pair<char, vector<int>> &b) {return a.second == b.second ? a.first < b.first : a.second > b.second;}
};
