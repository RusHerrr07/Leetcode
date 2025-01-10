class Solution {
public:
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string>ans;
        vector<int>maxf(26,0);
        for(auto& x:b) {
            vector<int>f(26,0);
            for(auto& c:x) f[c-'a']++;
            for(int i=0;i<26;++i) maxf[i]=max(maxf[i],f[i]);
        }
        for(auto& x:a){
            vector<int>f(26,0);
            for(auto& c:x)f[c-'a']++;
            bool issubset=true;
            for(int i=0;i<26;++i) {
                if(f[i]<maxf[i]) {
                    issubset=false;
                    break;
                }
            }
            if(issubset)ans.push_back(x);
        }
        return ans;
    }
};
