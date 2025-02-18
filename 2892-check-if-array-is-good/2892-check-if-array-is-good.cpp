class Solution {
public:
    bool isGood(vector<int>& nums) {
      map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        int n=nums.size();
        int x=n-1;
        if(mp[x]!=2)return false;
        x--;
        for(int i=x;i>=1;i--){
            if(mp[i]!=1)return false;
        }
        return true;
        
    }
};