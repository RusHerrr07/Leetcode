class Solution {
public:
    int solve(int index,int &width,vector<vector<int>>&books,vector<int>&dp){
        if(index>=books.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int sum=0;
        int maxi=0;
        int ans=1e9;
        for(int i=index;i<books.size();i++){
            sum+=books[i][0];
            maxi=max(maxi,books[i][1]);
            if(sum<=width){
                ans=min(ans,solve(i+1,width,books,dp)+maxi);
            }
        }
        return dp[index]= ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int>dp(books.size(),-1);
        return solve(0,shelfWidth,books,dp);
    }
};