class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int cnt=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)mp[s[i]]++;
        for(auto &i:mp){
            if(i.second>2){
                int freq=i.second;
                if(freq &1){
                    cnt+=(freq-1);
                }
                else{
                    cnt+=(freq-2);
                }
            }
        }
        return n-cnt;
        
    }
};