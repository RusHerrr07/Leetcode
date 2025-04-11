class Solution {
    int dp[5000+1][2+1];
    int solve(vector<int>&prices,int idx,int n,int isBuy){
        if(idx>=n) return 0;
        int ans=0;
        if(dp[idx][isBuy]!=-1) return dp[idx][isBuy];
        if(isBuy){
            int buy=-prices[idx]+solve(prices,idx+1,n,0);
            int skip=solve(prices,idx+1,n,1);
            ans=max(skip,buy);
            dp[idx][isBuy]=ans;
        }

        else{
            int sell=prices[idx]+solve(prices,idx+2,n,1);
            int skip=solve(prices,idx+1,n,0);
            ans=max(skip,sell);
            dp[idx][isBuy]=ans;
        }
        return dp[idx][isBuy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,n,1);
    }
};