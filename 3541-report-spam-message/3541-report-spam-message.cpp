class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& banned) {

        set<string>st(banned.begin(),banned.end());
        int cnt=0;
        for(auto &i:message){
            if(st.find(i)!=st.end())cnt++;
        }

        return cnt>1;
        
    }
};