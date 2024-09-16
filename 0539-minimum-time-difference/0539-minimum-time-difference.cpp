class Solution {
    static bool cmp(const string& a, const string& b) {
        string x1 = a.substr(0, 2), x2 = b.substr(0, 2);
        return x1 == x2 ? a.substr(3, 2) < b.substr(3, 2) : x1 < x2;
    }

    int timeToMinute(const string& t) {
        return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
    }
public:
    int findMinDifference(vector<string>& tp) {
        sort(tp.begin(), tp.end(), cmp);
        int n = tp.size(), md = INT_MAX;
        for (int i = 1; i < n; i++) {
            int d = timeToMinute(tp[i]) - timeToMinute(tp[i - 1]);
            md = min(md, d);
        }
        int f = timeToMinute(tp[0]), l = timeToMinute(tp[n - 1]);
        return min(md, 1440 - l + f);
        
    }
};