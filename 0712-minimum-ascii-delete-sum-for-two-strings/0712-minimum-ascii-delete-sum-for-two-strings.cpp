class Solution {
int dp[1001][1001];
int solve(string &s,string &t,int i,int j,int n,int m){
    if (i==n){
        int sum=0;
        for(int x=j;x<m;x++){
            sum+=int(t[x]);
        }
        return sum;
    }

    if (j==m) {
        int sum=0;
        for(int x=i;x<n;x++){
            sum+=int(s[x]);
            
        }
        return sum;

    }
    if(dp[i][j]!=-1)return dp[i][j];
    // if(i>=n || j>=m)return 1e9;
    if(s[i]==t[j]){
       dp[i][j]= solve(s,t,i+1,j+1,n,m);
    }
    else{
        int remove1=int(s[i])+solve(s,t,i+1,j,n,m);
        int remove2=int(t[j])+solve(s,t,i,j+1,n,m);
        dp[i][j]=min(remove1,remove2);
    }
    return dp[i][j];
}
public:
    int minimumDeleteSum(string word1, string word2) {
         memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0,word1.size(),word2.size());
        
        
    }
};