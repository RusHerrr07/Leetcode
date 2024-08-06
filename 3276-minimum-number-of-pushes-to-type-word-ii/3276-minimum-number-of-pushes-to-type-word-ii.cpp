
class Solution{
public:
    int minimumPushes(string word){
        map<char,int> freq;
        for(const auto &ch:word)freq[ch]++;
        vector<int> f;
        for(const auto &p:freq)f.push_back(p.second);
        sort(f.rbegin(),f.rend());
        int cnt=0,k=1,ca=0;
        for(int x:f){
            if(ca>=8){ca=0;k++;}
            cnt+=x*k;
            ca++;
        }
        return cnt;
    }
};
