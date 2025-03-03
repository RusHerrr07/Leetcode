class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>hash(26,0);
        int n=s.size();
        int i=0, cnt=0;
        for(int j=0;j<s.size();j++){
            hash[s[j]-'a']++;
            while(hash['a'-'a']>0 && hash['b'-'a']>0 && hash['c'-'a']>0 ){
                cnt+=(n-j);
                hash[s[i]-'a']--;
                i++;
            }
        }
        return cnt;
    }
};
