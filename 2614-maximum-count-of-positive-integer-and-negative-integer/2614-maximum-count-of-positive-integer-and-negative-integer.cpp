class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0,neg=0;
        for(auto &i:nums){
            if(i>0)pos++;
            if(i<0)neg++;
        }
        return max(pos ,neg);
        
    }
};