class Solution {
public:
    vector<string> ans;
    vector<char> v={'a','b','c'};
    void solve( int n,string curr,vector<char> &v,int k)
    {
        if(ans.size()==k)
            return ;
        if(curr.size()==n)
        {
            ans.push_back(curr);
                return;
        }
        for(int i=0;i<3;i++)
        {
            if(curr.size()==0||curr[curr.size()-1]!=v[i])
            {
                curr+=v[i];
                solve(n,curr,v,k);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) 
    {
      
        solve(n,"",v,k);
        if(ans.size()==k)
            return ans.back();
        else
            return "";
        
        
    }
};
