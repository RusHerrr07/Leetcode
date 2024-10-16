class Solution {
bool isPalindrom(string &s, int i, int j) {
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
    string longestPalindrome(string s) {
        int maxi = 0;
        int n = s.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrom(s, i, j)) {
                    if (j - i + 1 > maxi) {
                        maxi = j - i + 1;
                        res = s.substr(i, maxi);
                    }
                }
            }
        }
        return res;
    }
};
