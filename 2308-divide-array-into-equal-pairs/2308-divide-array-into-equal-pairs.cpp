class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        for(auto &[val,freq]:mp){
            if(freq&1)return false;
        }
        return true;
        
    }
};