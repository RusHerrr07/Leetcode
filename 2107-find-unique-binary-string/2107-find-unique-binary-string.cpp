class Solution {
set<string>st;
string ans="";
void solve(int n,string s){
    if(s.size()==n){
        if(st.find(s)==st.end()){
            ans=s;
        }
        return ;
    }
    solve(n,s+'0');
    solve(n,s+'1');

}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums[0].size();
        for(auto &i:nums){
            st.insert(i);
        }
        cout<<n;
        solve(n,"");
        return ans;    
    }
};