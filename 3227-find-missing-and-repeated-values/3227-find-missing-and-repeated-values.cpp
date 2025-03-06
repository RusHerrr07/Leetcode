class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       vector<int>ans;
       int n=grid.size();
       int first=-1;
       int sec=-1;
       set<int>st;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val=grid[i][j];
            if(st.find(val)!=st.end()){
                first=val;
            }
            st.insert(val);
        }

       }
       for(auto &i:st){
        cout<<i<<" ";
       }
       int val=1;
        while(val<=n*n){
            if(st.find(val)==st.end()){
                sec=val;
                break;
            }
            val++;
        }

        return {first,sec};


       
        
    }
};