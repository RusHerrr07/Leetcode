class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {  
        vector<pair<int,int>> arr;
        for(int i = 0; i < nums1.size(); i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        
        int n = arr.size();
        int idx = n - 1;
        sort(arr.begin(),arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long maxi = 0;
        long long sum = 0;

        while(idx >= 0) {
            long long mini = arr[idx].first;
            long long value = arr[idx].second;
            pq.push(value);
            sum += value;

            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) {
                maxi = max(maxi, sum * mini);
            }
            idx--;
        }

        return maxi;
    }
};
