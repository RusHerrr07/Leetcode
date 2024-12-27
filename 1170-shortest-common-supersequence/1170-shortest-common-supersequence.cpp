class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> sonal(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i==0) sonal[i][j]=j;
                else if(j==0) sonal[i][j]=i;
                else if(str1[i-1]==str2[j-1]) sonal[i][j]=1+sonal[i-1][j-1];
                else sonal[i][j]=1+min(sonal[i-1][j],sonal[i][j-1]);
        string scs="";
        int i=n,j=m;
        while(i>0&&j>0) {
            if(str1[i-1]==str2[j-1]) {scs=str1[i-1]+scs;i--;j--;}
            else if(sonal[i-1][j]<sonal[i][j-1]) {scs=str1[i-1]+scs;i--;}
            else {scs=str2[j-1]+scs;j--;}
        }
        while(i>0) {scs=str1[i-1]+scs;i--;}
        while(j>0) {scs=str2[j-1]+scs;j--;}
        return scs;
    }
};