class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> hash(26, 0);
            int maxi=0;
            for (int j = i; j < n; j++) {
                hash[s[j] - 'a']++;
                maxi=max(maxi,hash[s[j] - 'a']);
                // cout << hash[s[j] - 'a'] << "-->" << s.substr(i, j - i + 1) << endl;
                if (maxi>= k) cnt++;
            }
        }
        return cnt;
    }
};
