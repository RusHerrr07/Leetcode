class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[j]-nums[i])==k) cnt++;
            }
        }
        return  cnt;
        
    }
};