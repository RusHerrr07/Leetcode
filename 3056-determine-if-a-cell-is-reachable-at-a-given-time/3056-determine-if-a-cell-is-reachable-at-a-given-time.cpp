
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int n = abs(fy - sy);
        int m = abs(fx - sx);

        int val = max(n, m);
        if(val == 0) return t != 1;

        return val <= t;
    }
};