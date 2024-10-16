class Solution {
    bool isPalindrome(string &s, int i, int j) {
        while (j >= i) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    vector<string> substr;
    vector<vector<string>> ans;

    void solve(string s, int idx, int n) {
        if (idx == n) {
            ans.push_back(substr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                substr.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, n);
                substr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        solve(s, 0, n);
        return ans;
    }
};

