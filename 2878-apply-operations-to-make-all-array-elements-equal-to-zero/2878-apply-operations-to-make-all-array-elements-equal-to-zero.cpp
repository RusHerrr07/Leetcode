class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
     
        // int n=nums.size();
        // for(int i=0;i<n-k;i++){
        //     int mini=INT_MAX;
        //     for(int j=i;j-i+1<=k && j<n;j++){
        //         mini=min(nums[j],mini);
        //     }
            
        //     for(int j=i;j-i+1<=k && j<n;j++){
        //         nums[j]-=mini;
        //         if(nums[j]<0)return false;
        //     }

        //     int left=i;
        //     while(left<n && nums[left]==0){
        //         left++;
        //     }
        //     if(left==i)return false;
        //     else i=left-1;
        // }

        // for(auto &i:nums){
        //     if(i!=0)return false;
        // }

        // return true;



        if(k==1)return true;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i>=k){
                sum-=nums[i-k];
            }
            nums[i]-=sum;
            sum+=nums[i];
            if(nums[i]<0)return false;
        }

        for(auto &i:nums){
            cout<<i<<" ";
        }

        if(nums[nums.size()-1]==0) return true;
        return false;
    }
};
