class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n & 1) return false;
        
        // stack<char>st;
        // int i = 0;
        
        // while (i < s.size()) {  
        //     if (s[i] == ')' && locked[i] == '1') {  
        //         if (st.empty()) return false;  
        //         auto &p = st.top();
        //         st.pop();
        //         if (p.second != true || p.first != '(') {
        //             return false;
        //         }
        //     }
        //     if (s[i] == '(' && locked[i] == '1') {  
        //         if (i == n - 1) {
        //             return false;
        //         }
        //         if (i + 1 < n) {
        //             if (s[i + 1] != ')' && locked[i + 1] != '0') return false;  
        //             else {
        //                 i += 2;
        //                 continue;  
        //             }
        //         }
        //     }
        //     st.push({s[i], locked[i] == '1'});  
        //     i++;  
        // }

        

        // return true;  

        int cnt=0;
        bool flag=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('|| locked[i]=='0')cnt++;
            else cnt--;
            if(cnt<0)flag=false;
        }
        cnt=0;
        reverse(s.begin(),s.end());
        reverse(locked.begin(),locked.end());
        for(int i=0;i<s.size();i++){
            if(s[i]==')'|| locked[i]=='0')cnt++;
            else cnt--;
            if(cnt<0)flag=false;
        }
        return flag;
    }
};
