class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size(), l = 0, r = 1;
        vector<pair<int, int>> v(n);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
            v[i] = {nums[i], i};
        sort(v.begin(), v.end());

        pq.push(v[0].second);
        while (r <= n) {
            if (r == n || abs(v[r].first - v[r - 1].first) > limit) {
                for (int i = l; i < r; i++) {
                    nums[pq.top()] = v[i].first;
                    pq.pop();
                }
                l = r;
            }
            if (r < n)
                pq.push(v[r].second);
            r++;
        }

        return nums;
    }
};
