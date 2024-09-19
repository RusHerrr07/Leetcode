class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int> mp;
        // for(int i = 0; i < nums.size(); ++i) {
        //     int diff = target - nums[i];
        //     if(mp.count(diff)) {
        //         return {mp[diff], i};
        //     }
        //     mp[nums[i]] = i;
        // }
        // return {};

        int n =nums.size(); 

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }

        return {};
    }
};
