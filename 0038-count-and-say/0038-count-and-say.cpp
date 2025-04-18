class Solution {
private:
    string RLE(string s){
        vector<pair<int,char>> p;
        int i=0;
        int n=s.size();
        while(i<n){
            char ch=s[i];
            int cnt=0;
            while(i<n && s[i]==ch){
                i++;
                cnt++;
            }
            p.push_back({cnt,ch});
        }
        string ans="";
        for(auto &i:p){
            ans+=to_string(i.first);
            ans+=i.second;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
       if(n==1)return "1";
       string ans=countAndSay(n-1);
    //    cout<<ans<<endl;
       return RLE(ans);
    }
};
