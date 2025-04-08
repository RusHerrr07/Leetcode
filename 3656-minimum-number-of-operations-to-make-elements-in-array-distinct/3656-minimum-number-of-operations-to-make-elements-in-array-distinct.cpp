class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int cnt=0;
        set<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            int val=nums[i];
            if(st.find(val) != st.end())
{
                while(i>=0){
                    i-=3;
                    cnt++;
                }
            }
            else{
                st.insert(val);
            }
        }

        return cnt;
       
    }
};
