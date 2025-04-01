class Solution {
private:
    map<int, int> mp;
    int dp[2001][2001]; 

    bool solve(int pos, int end, int jump) {
        if (pos == end) return true;
        if (dp[mp[pos]][jump] != -1) return dp[mp[pos]][jump];
        
        bool ans = false;
        for (int i = jump - 1; i <= jump + 1; i++) {
            if (i > 0 && mp.find(pos + i) != mp.end()) {
                ans |= solve(pos + i, end, i);
            }
        }
        return dp[mp[pos]][jump] = ans;
    }

public:
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = i;
        }
        memset(dp, -1, sizeof(dp));
        if (stones[1] != stones[0] + 1) return false;
        return solve(stones[1], stones.back(), 1);
    }
};