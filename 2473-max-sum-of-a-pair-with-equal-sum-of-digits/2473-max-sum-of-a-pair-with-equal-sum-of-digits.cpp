class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            int sum=0;
            for(auto &j:s){
                sum+=j-'0';
            }
            if(mp.count(sum)){
                auto val=mp[sum];
                maxi=max(val+nums[i],maxi);
                mp[sum]=max(val,nums[i]);
            }
            else
            mp[sum]=nums[i];

        }
        return maxi!=0?maxi:-1;
        
    }
};