class Solution {
public:
    int takeCharacters(string s, int k) {
        int mini=INT_MAX;
        vector<int>cnt(3,0);
        for(auto &i:s){
            cnt[i-'a']++;
        }
        if(cnt['a'-'a']<k || cnt['b'-'a']<k || cnt['c'-'a']<k){
            return -1;
        }
        int i=0;
        int maxi=0;
        vector<int>hash(3,0);
        for(int j=0;j<s.size();j++){
            char ch=s[j];
            hash[ch-'a']++;
            while(hash[ch-'a']>cnt[ch-'a']-k){
                hash[s[i]-'a']--;
                i++;
            }
            maxi=max(maxi,j-i+1);
        }

        return s.size()-maxi;
        
    }
};