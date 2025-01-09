class Solution {
public:
    int minCut(string &s) {
        int n = s.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0]=-1;
        auto PalindromeHaiKya =[](const string &s,int i,int j)->bool {
           while(j>=i) {
           if (s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
       };
       for (int i=0; i<n;i++) {
            for (int j=0; j<=i; j++) {
                int take =INT_MAX;
                if (PalindromeHaiKya(s,j,i)) {
                    take =1+dp[j];
                }
                dp[i+1]=min(dp[i+1],take);
            }
        }
        return dp[n];
    }
};