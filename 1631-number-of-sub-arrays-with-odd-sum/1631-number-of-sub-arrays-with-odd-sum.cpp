class Solution {
    const int mod = 1e9+7;
    int dp[100000+1][3];

    int solve(vector<int>& arr, int i, int n, int rem) {
        if(i == n-1) {
            return rem&1;
            
        }
        if(dp[i][rem] != -1) return dp[i][rem];

        int take = solve(arr, i+1, n, (rem + arr[i]) % 2);
        int skip = solve(arr, i+1, n, arr[i]%2 );
        dp[i][rem] = (take + skip) % mod;
        return dp[i][rem];
    }

public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0;
        int even=1;
        int rem=0;
        int ans=0;
        for(int i=0;i<n;i++){
            rem=(arr[i]+rem)%2;
            if(rem&1){
                ans=(ans+even)%mod;
                odd++;
            }
            else{
                ans=(ans+odd)%mod;
                even++;
            }
            
        }

        return ans;
    
    }
};