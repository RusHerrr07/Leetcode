class Solution {
vector<vector<int>> dp;  
int solve(vector<int>& arr, int i, int amount,int sum) {
    if (amount==sum)return 1; 
    if (i>=arr.size()||amount<sum) return 0; 
    if (dp[i][sum]!=-1) return dp[i][sum];  
    int val1=solve(arr,i+1,amount,sum);
    int val2=solve(arr,i,amount,sum+arr[i]);
    return dp[i][sum]=val1+val2;
}

public:
    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,0,amount,0);
    }
};