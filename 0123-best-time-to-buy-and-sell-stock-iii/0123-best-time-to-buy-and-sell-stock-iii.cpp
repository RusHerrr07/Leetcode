class Solution {
    int dp[100001][2][2];
int solve(vector<int>& prices,int i,bool buy,int limit,int n ){
    if(i==n)return 0;
    if(limit==2)return 0;
    int profit=0;
    if(dp[i][buy][limit]!=-1){
        return dp[i][buy][limit];
    }
    if(buy){
        int buyKrle=-prices[i]+solve(prices,i+1,0,limit,n);
        int skipKrde=solve(prices,i+1,1,limit,n);
        profit=max(buyKrle,skipKrde);
    
    }
    else{
        int sellKarde=prices[i]+solve(prices,i+1,1,limit+1,n);
        int skipkrde=solve(prices,i+1,0,limit,n);
        profit=max(sellKarde,skipkrde);
    }

   dp[i][buy][limit]= profit;
   return dp[i][buy][limit];
}
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,0,n);
        
    }
};