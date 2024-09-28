
class Solution {
public:
    long long maximumTotalSum(std::vector<int>& maximumHeight) {
        long long sum = 0;
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end(),greater<int>());
        int prev = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (maximumHeight[i] < prev) {
                sum += maximumHeight[i];
                prev = maximumHeight[i];
            } else {
                prev -= 1;
                if (prev <= 0) {
                    return -1;
                }
                sum += prev;
            }
        }

        return sum;
    }
};
