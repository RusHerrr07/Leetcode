class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int oneCnt = 0;
        vector<int> nums(arr.begin(), arr.end());

        for (auto &i : arr) {
            if (i == 1) oneCnt++;
            nums.push_back(i);
        }
        if(!oneCnt) return 0;

        int n = arr.size();
        int mini = INT_MAX;


        int j = 0, i = 0;
        int sum = 0;
        while (j < 2 * n) {
            sum += nums[j];
            if (j - i + 1 == oneCnt) {
                mini = min(mini, oneCnt - sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return mini;
    }
};
