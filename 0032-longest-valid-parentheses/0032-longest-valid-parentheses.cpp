class Solution {
public:
    int longestValidParentheses(string s) {
         int n = s.size(); // Define n here, after reading the string
    vector<int> dp(n + 1, 0); // Moved the dp declaration after n

    stack<int> st;
    int i = 0;
    st.push(-1);
    int ans=0;

    while(i < n) {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            ans=max(ans,i-st.top());
        }
            
        i++;
    }   

    return ans;

        
    }
};