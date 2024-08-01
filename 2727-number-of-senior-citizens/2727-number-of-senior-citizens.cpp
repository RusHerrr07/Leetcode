class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto &i : details) {
            if (i[11] - '0' > 6 || (i[11] - '0' == 6 && i[12] - '0' > 0)) {
                cnt++;
            }
        }
        return cnt;
    }
};
