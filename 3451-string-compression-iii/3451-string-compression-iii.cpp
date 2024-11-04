class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        string ans = "";
        int n = word.size();
        
        while (i < n) {
            int cnt = 0;
            char currentChar = word[i];
            
            while (i < n && word[i] == currentChar && cnt < 9) {
                cnt++;
                i++;
            }
            
            ans += to_string(cnt);
            ans += currentChar;
        }
        
        return ans;
    }
};
