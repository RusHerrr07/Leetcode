#define INF INT_MAX / 2
#define REP(i,a,b) for(int i=a;i<b;i++)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX_OP 100

class Solution {
public:
    vector<vector<vector<int>>> m;
    int solve(int i, int o1, int o2, vector<int>& n, int k, int op1, int op2) {
        if(i == n.size()) return 0;
        if(m[i][o1][o2] != -1) return m[i][o1][o2];
        int c = INF, num = n[i];
        c = MIN(c, num + solve(i + 1, o1, o2, n, k, op1, op2));
        if(o1 < op1) {
            int newNum = (num + 1) / 2;
            c = MIN(c, newNum + solve(i + 1, o1 + 1, o2, n, k, op1, op2));
        }
        if(o2 < op2 && num >= k) {
            int newNum = num - k;
            c = MIN(c, newNum + solve(i + 1, o1, o2 + 1, n, k, op1, op2));
        }
        if(o1 < op1 && o2 < op2) {
            int temp = (num + 1) / 2;
            if(temp >= k) {
                int newNum = temp - k;
                c = MIN(c, newNum + solve(i + 1, o1 + 1, o2 + 1, n, k, op1, op2));
            } else {
                c = MIN(c, temp + solve(i + 1, o1 + 1, o2 + 1, n, k, op1, op2));
            }
            if(num >= k) {
                temp = num - k;
                int newNum = (temp + 1) / 2;
                c = MIN(c, newNum + solve(i + 1, o1 + 1, o2 + 1, n, k, op1, op2));
            }
        }
        return m[i][o1][o2] = c;
    }
    int minArraySum(vector<int>& n, int k, int op1, int op2) {
        int sz = n.size();
        m.assign(sz + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return solve(0, 0, 0, n, k, op1, op2);
    }
};
