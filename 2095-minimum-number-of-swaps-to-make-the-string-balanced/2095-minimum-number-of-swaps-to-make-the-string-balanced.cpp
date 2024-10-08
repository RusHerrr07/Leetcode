
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if (n == 0) return 0;
        stack<char> st;
        for (auto &i : s) {
            if (!st.empty() && st.top() == '[' && i == ']') {
                st.pop();
            } else {
                st.push(i);
            }
        }
        int size = st.size();
        if(size%4!=0){
            return (size/4)+1;
        }
        else{
            return size/4;
        }
    }
};
