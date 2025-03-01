class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>ans(n,0);
        while(i<n-1){
            if(nums[i]==nums[i+1]){
               nums[i]= nums[i]*2;
               nums[i+1]=0;
               
            
               
            }
            i++;
           
        }

        //first option-->

        // for(auto &i:nums)cout<<i<<" ";
        // int idx=0;

        // for(int i=0;i<nums.size();i++){
        //     int val=nums[i];
        //     if(val!=0)ans[idx++]=val;


        
        // }
         //return ans;

        //second option-->
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
        int idx=i+1;
        while(idx<nums.size()&&nums[idx]==0)idx++;
        if(idx<nums.size())swap(nums[i],nums[idx]);
    }
}



        return nums;

        
    }
};