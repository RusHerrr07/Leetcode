class Solution {
vector<long long> dp;
// private:
//     static bool cmp(vector<int> a, vector<int> b){
//         if(b[1] == a[1] && a[0] == b[0]){
//             int val1 = a[1] - a[0] + a[2];
//             int val2 = b[1] - b[0] + b[2];
//             return val1 > val2;
//         }
//         else if(a[1] != b[1]){
//             return a[1] < b[1];
//         }
//         else{
//             return a[0] < b[0];
//         }
//     }

long long solve(vector<vector<int>>& rides, int i, int n){
    
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    int left = i + 1, right = n - 1, idx = n;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(rides[mid][0] >= rides[i][1]){
            idx = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    long long pick = rides[i][1] - rides[i][0] + rides[i][2] + solve(rides, idx, n);
    long long not_pick = solve(rides, i + 1, n);
    return dp[i] = max(pick, not_pick);
}

public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());

 // long long profit = rides[0][1] - rides[0][0] + rides[0][2];
        // long long maxi = profit;
        // int prev = rides[0][1];

        // for(int i = 1; i < rides.size(); i++){
        //     if(rides[i][0] >= prev){
        //         prev = rides[i][1];
        //         profit += rides[i][1] - rides[i][0] + rides[i][2];
        //         maxi = rides[i][1] - rides[i][0] + rides[i][2];
        //     }
        //     else {
        //         long long val = rides[i][1] - rides[i][0] + rides[i][2];
        //         if(maxi < val){
        //             profit -= maxi;
        //             profit += val;
        //             maxi = val;
        //             prev = rides[i][1]; 
        //         }
        //     }
        // }

        
        dp.assign(rides.size() + 1, -1); 
        return solve(rides, 0, rides.size()); 
    }
};
