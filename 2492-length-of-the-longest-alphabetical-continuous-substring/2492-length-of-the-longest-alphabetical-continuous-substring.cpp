class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int maxi = 0;

        for (int i = 0; i < n;) {
            int cnt = 1;
            char ch = s[i];

            while (i + 1 < n && s[i] + 1 == s[i + 1]) {
                cnt++;
                i++;
            }

            maxi = max(maxi, cnt);
            i++;
        }

        return maxi;
    }
};
