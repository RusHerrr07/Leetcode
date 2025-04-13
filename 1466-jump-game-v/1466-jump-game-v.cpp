class Solution {
    vector<int> dp;
    
    int solve(vector<int>& arr, int idx, int d, int n) {
        if (idx<0 ||  idx>=n) return 0;

        if (dp[idx] != -1) return dp[idx];
        
        int ans = 0;
        for (int i = 1; i <= d; i++) {
            if(i+idx<n){
                if(arr[idx]>arr[i+idx]){
                    ans=max(ans,1+solve(arr,idx+i,d,n));
                }
                else break;
            }
            else break;

           
        }

        for (int i = 1; i <= d; i++) {
             if(idx-i>=0){
                if(arr[idx]>arr[idx-i]){
                    ans=max(ans,1+solve(arr,idx-i,d,n));
                }
                else break;
            }
            else break;

        }
        
        return dp[idx] = ans;
       
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.resize(n, -1);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, i, d, n));
        }
        
        return ans+1;
    }
};
