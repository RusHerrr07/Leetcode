int dp[51111][30][4], n;
class Solution {
public:
    int calculateDifference(int a, int b) {
        return abs(a - b);
    }

    bool isValid(int current, int streak, int length, int previous) {
        if (current != previous) return streak >= 3 && length >= 3;
        return streak + length >= 3;
    }

    string minCostGoodCaption(string s) {
        n = s.size();
        if (n < 3) return "";
        memset(dp, 2, sizeof(dp));
        
        for (int i = 0; i < 26; ++i) {
            dp[n][i][0] = 0;
        }

        for (int i = n; i > 0; --i) {
            for (int currentChar = 0; currentChar < 26; ++currentChar) {
                for (int streak = 0; streak <= 3; ++streak) {
                    for (int nextChar = 0; nextChar < 26; ++nextChar) {
                        if (nextChar == currentChar) {
                            dp[i - 1][nextChar][min(streak + 1, 3)] = min(dp[i - 1][nextChar][min(streak + 1, 3)], dp[i][currentChar][streak] + calculateDifference(s[i - 1] - 'a', nextChar));
                        } else if (streak == 3) {
                            dp[i - 1][nextChar][1] = min(dp[i - 1][nextChar][1], dp[i][currentChar][streak] + calculateDifference(s[i - 1] - 'a', nextChar));
                        }
                    }
                }
            }
        }

        int minCost = n * 26;
        for (int ch = 0; ch < 26; ++ch) {
            minCost = min(minCost, dp[0][ch][3]);
        }
        printf("%d\n", minCost);

        int currentCost = 0, length = 3, lastChar = -1;
        string result = "";

        for (int i = 0; i < n; ++i) {
            for (int ch = 0; ch < 26; ++ch) {
                bool found = false;
                for (int streak = 0; streak <= 3; ++streak) {
                    if (isValid(ch, streak, length, lastChar) && currentCost + dp[i][ch][streak] == minCost) {
                        result += 'a' + ch;
                        currentCost += calculateDifference(s[i] - 'a', ch);
                        found = true;
                        if (ch == lastChar) ++length;
                        else {
                            lastChar = ch;
                            length = 1;
                        }
                        break;
                    }
                }
                if (found) break;
            }
        }
        return result;
    }
};
