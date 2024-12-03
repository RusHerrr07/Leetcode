class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(), spaces.end());
        string ans = s.substr(0, spaces[0]);
        int prev = spaces[0];
        ans += ' ';
        for (int i = 1; i < spaces.size(); i++) {
            ans += s.substr(prev, spaces[i] - prev);
            prev = spaces[i];
            ans += " ";
        }
        for(int  i=prev ;i<s.size();i++){
            ans+=s[i];
        }

        return ans;
       
    }
};
