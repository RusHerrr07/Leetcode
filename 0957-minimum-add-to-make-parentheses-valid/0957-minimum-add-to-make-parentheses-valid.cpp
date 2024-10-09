class Solution {
public:
    int minAddToMakeValid(string s) {
    
        // int n = s.size();
        // stack<char> st;
        // for (auto &i : s) {
        //     if (!st.empty() && i == ')' && st.top() == '(') {
        //         st.pop();
        //     } else {
        //         st.push(i);
        //     }
        // }
        // return st.size();



        


        // optimal----->with o(1) space and o(n) time;
        int temp=0;
        int cnt=0;
        int n=s.size();
        for(auto &i:s){
            if(i=='('){
                temp++;
            }
            else{
                if(temp>0)temp--;
                else cnt++;
            }
        }

        return temp+cnt;
        
    }
};