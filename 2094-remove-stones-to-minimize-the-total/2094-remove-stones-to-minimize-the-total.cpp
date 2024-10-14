
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for (auto i : piles) pq.push(i);
        while (k != 0) {
            int val = pq.top();
            pq.pop();
            pq.push(ceil(val / 2.0));
            k--;
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
