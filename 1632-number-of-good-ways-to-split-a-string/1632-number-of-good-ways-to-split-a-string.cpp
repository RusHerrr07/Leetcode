class Solution {
public:
    int numSplits(string s) {
       map<char,int >mp;
       for(auto &i:s){
        mp[i]++;
       }
       set<char>st;
       int cnt =0;
       for(auto &i:s){
        mp[i]--;
        if(mp[i]==0)mp.erase(i);
        st.insert(i);
        if(st.size()==mp.size())cnt++;
       }

       return cnt;
        
    }
};