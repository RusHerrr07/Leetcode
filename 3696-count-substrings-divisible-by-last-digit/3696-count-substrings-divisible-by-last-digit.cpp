class Solution {
public:
    long long countSubstrings(string s) {
        vector<vector<long long>>gra(10,vector<long long>(10,0));
        int n=s.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int x=s[i]-'0';
            for(int j=1;j<=9;j++){
                vector<long long>v(10,0);
                v[x%j]++;
                for(int k=0;k<=9;k++){
                    v[(k*10+x)%j]+=gra[j][k];
                }
                for(int k=0;k<=9;k++){
                    gra[j][k]=v[k];
                }
            }
            ans+=gra[x][0];
        }
        return ans;
    }
};