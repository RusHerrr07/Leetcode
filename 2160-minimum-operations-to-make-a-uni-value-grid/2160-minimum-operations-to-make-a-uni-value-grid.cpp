class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<int>nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        n=nums.size();
        int mid=0;
        if(!(n&1)) 
        mid=nums[n/2-1];
        else 
        mid=nums[n/2];
        cnt=0;
        for(auto &i:nums){
            if(i%x!=mid%x) return -1;
            int diff=abs(mid-i);
            cnt+=diff/x;
        }
        return cnt;
    }
};
