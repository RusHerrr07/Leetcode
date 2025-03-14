
class Solution {
private:
    bool isValid(vector<int>& weights, int mid, int days) {
        int cnt = 1, sum = 0;
        for (auto &w : weights) {
            if (sum + w <= mid) {
                sum += w;
            } else {
                cnt++;
                sum = w;
            }
            if (cnt > days) return false;
        }
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long total = accumulate(weights.begin(), weights.end(), 0LL);
        int low = *max_element(weights.begin(), weights.end());
        int high = total;
        int ans = -1;
        while (high >= low) {
            int mid = (low + high) / 2;
            if (isValid(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

