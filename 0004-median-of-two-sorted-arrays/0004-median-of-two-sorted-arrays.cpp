class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        for(auto &i:nums1){
            nums.push_back(i);

        }
        for(auto &i:nums2){
            nums.push_back(i);

        }
        sort(nums.begin(),nums.end());
        int size=nums.size();
      
        double ans=0.0;
        if(size&1){
          
            int idx=size/2;
            
            ans=nums[idx];

        }
        else{
        int idx1=size/2;
        int idx2=idx1-1;
        ans=(nums[idx1]+nums[idx2])/2.0;
        
            

        }

        return ans;
        
    }
};