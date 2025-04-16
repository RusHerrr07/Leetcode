class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int ans=-1;
       int diff=INT_MAX;
       int n=nums.size();
       sort(nums.begin(),nums.end());
       for(int i=0;i<n-1;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
             int sum=nums[i]+nums[left]+nums[right];

        int val=min(diff,abs(target-sum));
        if(val<diff){
            ans=sum;
            diff=val;
        }
        if(sum>target){
            right--;
        }
        else{
            left++;
        }

        }
        
       }

       return ans;
        
    }
};