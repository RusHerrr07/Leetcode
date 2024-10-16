class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        string ans="";
        for (auto& ch : s) mp[ch]++;
        for (auto& p : mp) pq.push({p.second,p.first});
        while (!pq.empty()) {
            auto [first,ch1]=pq.top();pq.pop();
            if (pq.empty()) {
                if (first>1) return "";
                ans+=ch1;
                break;
            }
            auto [sec,ch2]=pq.top();pq.pop();
            ans+=ch1;
            first-=1;
            ans+=ch2;
            sec-=1;
            if (first>0) pq.push({first,ch1});
            if (sec>0) pq.push({sec,ch2});
        }
        return ans;
    }
};
