class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int sec = 0;
        bool chg = true;
        
        while (chg) {
            chg = false;
            for (int i = 0; i < s.length() - 1; ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    i++;
                    chg = true;
                }
            }
            if (chg) {
                sec++;
            }
        }
        
        return sec;
    }
};
