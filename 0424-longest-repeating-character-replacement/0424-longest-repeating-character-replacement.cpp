class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> freq(26, 0);
        int maxFreq = 0;
        
        for (j = 0; j < n; j++) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            if (j - i + 1 - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
        }
        
        return maxi;
    }
};