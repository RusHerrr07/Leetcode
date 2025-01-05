class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long>suff(shifts.size(),0);
        int n = shifts.size();
        suff[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--) {
            suff[i]=suff[i+1]+shifts[i];
        }
        for(int i=0;i<n;i++) {
            s[i]=(char)((s[i]-'a'+suff[i]+26)%26+'a');
        }

        
        return s;
    }
};
