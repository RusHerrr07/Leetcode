
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        string scs="";
        int i=n,j=m;
        while(i>0&&j>0) {
            if(str1[i-1]==str2[j-1]) {scs=str1[i-1]+scs;i--;j--;}
            else if(dp[i-1][j]<dp[i][j-1]) {scs=str1[i-1]+scs;i--;}
            else {scs=str2[j-1]+scs;j--;}
        }
        while(i>0) {scs=str1[i-1]+scs;i--;}
        while(j>0) {scs=str2[j-1]+scs;j--;}
        return scs;
    }
};
