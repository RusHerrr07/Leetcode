class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int val=i*j;
                if(nums[i]==nums[j] && (val%k==0))cnt++;
            }
        }
        return cnt;
        
    }
};