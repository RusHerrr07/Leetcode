class Solution {
public:
    bool canJump(vector<int>& nums) {
        int val=nums[0];
        if(nums.size()==1){
            return true;
        }
        if(nums[0]==0)return false;

        
        for(int i=1;i<nums.size();i++){
            val--;
            if(val<=0 && nums[i]==0 && i!=nums.size()-1)return false;
            val=max(val,nums[i]);

        }

        return true;
        
    }
};