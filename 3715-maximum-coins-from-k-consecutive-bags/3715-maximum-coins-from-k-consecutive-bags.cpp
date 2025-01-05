using ll = long long;
const int N=1e5+10;
ll s[N];
int l[N], r[N], c[N];
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& a, int k) {
        int n= a.size();
        sort(a.begin(),a.end(),[](auto&x,auto&y){
            return x[0] < y[0];
        });
        s[0]=0;
        for(int i=0; i<n; ++i){
            l[i+1]=a[i][0];
            r[i+1]=a[i][1];
            c[i+1]=a[i][2];
            s[i+1]=s[i]+1ll*c[i+1]*(r[i+1]-l[i+1]+1);
        }
        ll ret = 0, cur = 0;
        for(int i=1;i<=n;++i){
            int p=l[i]+k-1;
            int j = lower_bound(r+1,r+1+n,p)-r;
            cur = s[j-1] - s[i-1];
            if(j <= n && p>= l[j]){
                cur += 1ll * c[j] * (p - l[j] + 1);
            }
            ret = max(ret, cur);
            p = r[i] - k + 1;
            j = lower_bound(r+1,r+1+n,p)-r;
            cur = s[i]-s[j];
            if(p>=l[j]){
                cur +=1ll*c[j]*(r[j]-p+1);
            }
            ret = max(ret,cur);
        }
        return ret;
    }
};