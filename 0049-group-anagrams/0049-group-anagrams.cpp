class Solution {
private:
    bool isValid(string &s,string &t){
        int n=s.size();
        int m=t.size();
        if(n!=m)return false;
        vector<int>hash1(26,0),hash2(26,0);
        for(int i=0;i<n;i++){
            hash1[s[i]-'a']++;
            hash2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //  vector<vector<string>>ans;
    //  int n=strs.size();
    //  vector<bool>vist(n+1,false);
    //  for(int i=0;i<strs.size();i++){
    //     if(vist[i]){
    //         continue;
    //     }
    //     vist[i]=true;
    //     vector<string>temp;
    //     temp.push_back(strs[i]);
    //     for(int j=i+1;j<n;j++){
    //         if(!vist[j] && isValid(strs[i],strs[j])){
    //             temp.push_back(strs[j]);
    //             vist[j]=true;
    //         }
    //     }
    //     ans.push_back(temp);
    //  }
    //  return ans;



     map<string,vector<string>>mp;
     for(int i=0;i<strs.size();i++){
        string s=strs[i];
        sort(s.begin(),s.end());
        mp[s].push_back(strs[i]);
     }
     vector<vector<string>>ans;
     for(auto &x:mp){
        ans.push_back(x.second);
     }
     return ans;
    }
};
