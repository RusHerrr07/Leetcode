class Solution {
    // int isPalindrome(string &s,int i,int j){
    //   while(j>=i){
    //     if(s[i]!=s[j])return false;
    //     i++;
    //     j--;
    //   }
    //   return true;
    // }
public:
    int countPalindromicSubsequence(string s) {
        // set<string>st;
        // int n=s.size();
        //     for(int i=0;i+3<n;i++){
        //     if(isPalindrome(s,i,i+3)){
        //         st.insert(s.substr(i,3));
        //     }
        // }
        // return st.size();

        // vector<int>hash(26,0);
        // int cnt=0;
        // for(auto &i:s){
        //     hash[i-'a']++;
        //     int val=hash[i-'a'];
        //     if(val>=3){
        //         cnt++;
        //     }
        //     else if(val==2 && i-1>=0 && s[i]!=s[i-1])cnt++;

        // }

        // return cnt;




        //bakchodi bhot ho gai abb bc-->


               map<char,pair<int,int>>mp;
        for(auto &i:s){
            mp[i]={-1,-1};
        }
        int n=s.length();

        for(int i=0;i<n;i++){
            if(mp[s[i]].first==-1){
                mp[s[i]].first=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(mp[s[i]].second==-1){
                mp[s[i]].second=i; 
            }
        }
        int cnt=0;

        for(auto &i:mp){
            set<char>st;
            
            for(int x=i.second.first+1;x<i.second.second;x++){
                st.insert(s[x]);
            }
            cnt+=st.size();
        }

        return cnt;

        
    }
};