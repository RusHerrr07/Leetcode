class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        
        if (n >= 2) {
            if (s[0] == 'H' && s[1] == 'H') return -1;
            if (s[n - 1] == 'H' && s[n - 2] == 'H') return -1;
        }

        if(n==1 && s[0]=='H')return -1;
       
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'H') {
                if (i - 1 >= 0 && s[i - 1] == '*') continue;
                if (i + 1 < n && i - 1 >= 0 && s[i - 1] == 'H' && s[i + 1] == 'H') return -1;
                
                if (i + 1 < n && s[i + 1] == '.') {
                    s[i + 1] = '*';
                    cnt++;
                } else if (i - 1 >= 0 && s[i - 1] == '.') {
                    s[i - 1] = '*';
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};
