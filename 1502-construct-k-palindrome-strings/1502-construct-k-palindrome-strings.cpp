class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k)return false;
        map<char,int>mp;
        int cnt=0;
        for(auto &i:s){
            mp[i]++;
        }
        for(auto &i:mp){
            if(i.second & 1)cnt++;
        }

        return cnt<=k;
        
    }
};