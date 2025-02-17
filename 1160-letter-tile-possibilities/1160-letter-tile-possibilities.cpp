class Solution {
    set<string>ans;

    void solve(string &s,string temp,vector<bool>&vist) {
        if (!temp.empty())ans.insert(temp);
        
        for (int i=0;i< s.size();i++) {
            if (!vist[i]){
                vist[i]=true;
                solve(s,temp+s[i],vist);
                vist[i]=false;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        vector<bool>vist(n,false);
        string temp="";
        solve(tiles,temp,vist);
        return ans.size();
    }
};
