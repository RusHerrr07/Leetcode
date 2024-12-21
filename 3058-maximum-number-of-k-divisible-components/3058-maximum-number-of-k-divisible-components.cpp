class Solution {
    const int M =202020;
    vector<vector<int>>a;
    vector<bool>v;
    int k;

    int dfs(int n,vector<int>&b, long long&s) {
        v[n] =true;
        long long c =b[n];
        int x=0;

        for (int i:a[n]) {
            if (!v[i]) {
                long long t = 0;
                x+= dfs(i,b,t);
                c+=t;
            }
        }
         if (c%k==0) {
            x++;
            s=0;
        } else{
            s=c;
        }

        return x;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& b, int k) {
        this->k =k;
        a.resize(n);
        v.resize(n,false);

        for (auto &i:e) {
            int u =i[0];
            int t=i[1];
            a[t].push_back(u);
            a[u].push_back(t);
        }

        long long s=0;
        return dfs(0,b,s);
    }
};
