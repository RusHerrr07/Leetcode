class Solution {
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int idx,int sum,int target,vector<int>temp){
        if(sum>=target){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        int n=nums.size();
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums,i,sum+nums[i],target,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<int>temp;
     solve(candidates,0,0,target,temp);
     return ans;
        
    }
};