class Solution {
private:
    bool isValid(vector<int>& arr, int s, int mid, int n) {
        int cnt = 1;
        int sum = 0;

        for (auto &val : arr) {
            if (sum + val <= mid) {
                sum += val;
            } else {
                cnt++;
                sum = val;
            }
            if (cnt > s) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& A, int B) {
        long long total = accumulate(A.begin(), A.end(), 0LL);
        int n = A.size();
        int low = *max_element(A.begin(), A.end());
        int high = total;
        int ans = -1;

        while (high >= low) {
            int mid = (low + high) / 2;
            if (isValid(A, B, mid, n)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

};
