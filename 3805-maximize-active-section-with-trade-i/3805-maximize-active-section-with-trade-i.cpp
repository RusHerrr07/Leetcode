class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int l = 0, r;
        vector<int> zs;
        for(r = 0; r <= n; r++) {
            if(r == n || s[r] == '1') {
                if(l < r) zs.push_back(r - l);
                l = r + 1;
            }
        }
        int mx = 0;
        for(int i = 1; i < zs.size(); i++) mx = max(mx, zs[i-1] + zs[i]);
        int res = 0;
        for(char c: s) if(c == '1') res++;
        return res + mx;
    }
};