class Solution {
private:
 string ConvertIntoRevert(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = '1' - s[i] + '0';
        }
        return s;
    }

public:
    char findKthBit(int n, int k) {
        vector<string>dp(n+1);
        dp[1]="0";
        for(int i=2;i<=n;i++){
            string prev=dp[i-1];
            string revert=ConvertIntoRevert(prev);
            reverse(revert.begin(),revert.end());
            dp[i]=prev+'1'+revert;
        }

        string ans=dp[n];
        return ans[k-1];

         
        
    }
};













/*

class Solution {
    string ConvertIntoRevert(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = '1' - s[i] + '0';
        }
        return s;
    }
    
    string solve(int n) {
        if (n == 1) return "0";
        string ans = solve(n - 1);
        string revert = ConvertIntoRevert(ans);
        reverse(revert.begin(), revert.end());
        return ans + '1' + revert;
    }
    
public:
    char findKthBit(int n, int k) {
        string temp = solve(n);
        return temp[k - 1];
    }
};
*/


