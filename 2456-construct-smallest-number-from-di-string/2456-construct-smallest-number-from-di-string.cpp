
class Solution {
vector<string>nums;
void solve(string&pattern, int i,int n,string num,vector<bool>&vist) {
    if (i==n) {
        nums.push_back(num);
        return;
    }
    
    for (int d=1;d<=9;d++) {
        if (vist[d])continue;
        if (i>0) {
            if ((pattern[i-1]=='D'&&num.back()-'0'<=d) || 
                (pattern[i-1]=='I'&& num.back()-'0'>= d))
                continue;
        }
        
        vist[d]=true;
        solve(pattern,i+1, n,num+char('0'+d),vist);
        vist[d]=false;
    }
}

public:
string smallestNumber(string pattern) {
    int n = pattern.size();
    vector<bool> vist(10, false);
    solve(pattern,0,n + 1,"",vist);
    return *min_element(nums.begin(), nums.end());
}
};

