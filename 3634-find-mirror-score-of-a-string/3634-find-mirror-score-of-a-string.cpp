class Solution {

public:
    long long calculateScore(string s) {
        long long cnt=0;
        map<char,vector<int>> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch='z'-(s[i]-'a');
            if(mp[ch].size()>0){
                
                int idx=mp[ch].back();
                cnt+=(i-idx);
                mp[ch].pop_back();
            }
            else{
                mp[s[i]].push_back(i);
            }
        }
        return cnt;
    }
};