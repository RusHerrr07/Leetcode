#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define Y cout<<"YES"<<endl
#define N cout<<"No"<<endl
#define greet cout<<"Hare Krishna"<<endl;
using pii = std::pair<int, int>;
#define mod 998244353
mt19937 rnd(time(0));
mt19937_64 rndl(time(0)); 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define add_to_ans(x) ans += (x)
#define condition(cond, true_val, false_val) ((cond) ? (true_val) : (false_val))
#define sum(a, b) ((a) + (b))
template <class A, class B> bool minimize(A &a, B b) { if (a > b) { a = b; return true; } return false; }
template <class A, class B> bool maximize(A &a, B b) { if (a < b) { a = b; return true; } return false; }

ll MOD = 1e9+7;
ll power(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a) % MOD; a = (a * a) % MOD; b >>= 1; } return ans; }
ll power1(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a); a = (a * a); b >>= 1; } return ans; }
ll prod(ll a, ll b) { ll c = 0; while (b > 0) { if ((b & 1) == 1) { c += a; } a <<= 1; b >>= 1; } return c; }

class Solution {
public:
    int minFlips(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        if (n % 2 && m % 2 && g[n / 2][m / 2]) add_to_ans(1);
        vector<int> s(3, 0);
        if (n % 2) for (int a = 0, b = m - 1; a < b; ++a, --b) s[sum(g[n / 2][a], g[n / 2][b])]++;
        if (m % 2) for (int a = 0, b = n - 1; a < b; ++a, --b) s[sum(g[a][m / 2], g[b][m / 2])]++;
        add_to_ans(condition(s[2] % 2, condition(s[1], s[1], 2), s[1]));
        rep(i, n / 2) rep(j, m / 2) {
            int a = g[i][j], b = g[n - 1 - i][j], c = g[i][m - 1 - j], d = g[n - 1 - i][m - 1 - j];
            int sm = sum(sum(a, b), sum(c, d));
            if (sm && sm != 4) add_to_ans(min(sm, 4 - sm));
        }
        return ans;
    }
};
