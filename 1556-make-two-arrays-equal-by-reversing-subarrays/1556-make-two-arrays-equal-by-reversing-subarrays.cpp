class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& nums) {
        // multiset<int>ms;
        // int n=nums.size();
        // for(auto &i:nums)ms.insert(i);
        // for(int i=0;i<n;i++)
        // {
        //     if(ms.count(target[i])==0) return false;

        // }
        // return true;

        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(int i=0;i<nums.size();i++)
        {
            if(target[i]!=nums[i])return false;

        }
        return true;
        
        
        
    }
};