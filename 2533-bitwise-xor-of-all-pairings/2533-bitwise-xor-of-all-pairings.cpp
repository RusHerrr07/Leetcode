class Solution {
   
    int ans = 0;
    void solve(vector<int>&arr) {
        for (const auto &it:arr)ans^=it;
    }
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // int ans=0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=0;j<nums2.size();j++){
        //         int ele=nums1[i]^nums2[j];
        //         ans^=ele;
        //     }
        // }
        // return ans;
        // int ele=0;
        // if(nums2.size()&1)
        // for(auto &i:nums1 )ele^=i;
        // int ans=0;
       
        // if(nums1.size()&1){
        //     for(auto &i:nums2){
        //      int x=ele^i;
        //     ans^=x;
        // }

        // }
        
        // return ans;;
        

        if(nums1.size()&1) solve(nums2);
        if(nums2.size()&1) solve(nums1);
        return ans;

      
        
    }
};