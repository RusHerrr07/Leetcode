class Solution {
public:
    int partitionString(string s) {

        int cnt=1;
        int n=s.size();
        set<char>st;
        for(auto &i:s){
            if(st.find(i)!=st.end()){
                st.clear();
                cnt++;
            }
          
                st.insert(i);
        
        
        
        }
        
        return cnt;
    }
};