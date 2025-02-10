class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans(nums.size(),0);
        int left=0;
        int cnt=0;
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot)cnt++;
            if(nums[i]<pivot){
                ans[idx]=nums[i];
                idx++;
            }
        }
        if(cnt==nums.size())return nums;
        int right=idx+cnt;
        int j=0;
        int x=idx+cnt;
        for(int i=0;i<nums.size();i++){
            if(j<cnt){
                ans[idx]=pivot;
                idx++;
                j++;
            }
            if(nums[i]>pivot){
                ans[right]=nums[i];
                right++;
            }
        }
        return ans;
    }
};

