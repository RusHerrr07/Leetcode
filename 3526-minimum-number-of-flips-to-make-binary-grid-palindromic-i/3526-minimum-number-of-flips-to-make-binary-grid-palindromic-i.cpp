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
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define all(x) (x).begin(), (x).end()
#define rall(X) X.rbegin(),X.rend()
#define rep(a, b) for (int a = 0; a < (b); a++)
template <class A, class B> bool minimize(A &a, B b) { if (a > b) { a = b; return true; } return false; }
template <class A, class B> bool maximize(A &a, B b) { if (a < b) { a = b; return true; } return false; }

ll MOD = 1e9+7;
ll power(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a) % MOD; a = (a * a) % MOD; b >>= 1; } return ans; }
ll power1(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a); a = (a * a); b >>= 1; } return ans; }
ll prod(ll a, ll b) { ll c = 0; while (b > 0) { if ((b & 1) == 1) { c += a; } a <<= 1; b >>= 1; } return c; }




/*─────────────────────────────────────────────────────────────────────────────────────
                      \U0001f33a राधा वल्लभ श्री हरिवंश \U0001f33a
──────────────────────────────────────────────────────────────────────────────────────*/
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
       
        int n = grid.size();
        int m = grid[0].size();
        int rowCnt=0;
        int colCnt=0;
        
       for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m / 2; ++j) {
            if(grid[i][j] != grid[i][m - j - 1]) {
                rowCnt++;
            }
        }
        }
        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n / 2; ++i) {
            if(grid[i][j] != grid[n - i - 1][j]) {
                   colCnt++;
                }
            }
        }
        
       return min(rowCnt,colCnt);
        
    }
};
