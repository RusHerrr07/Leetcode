
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long score = 0;
        priority_queue<int> pq;
        for (auto &i : nums) pq.push(i);
        while (!pq.empty() && k != 0) {
            int val = pq.top();
            pq.pop();
            score += val;
            pq.push((val + 2) / 3);
            k--;
        }
        return score;
    }
};
