class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // long long sum=accumulate(nums.begin(),nums.end(),0LL);
        // if(sum&1)return -1;
        // int req=sum/2;
        // sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     if(sum==req)return i;
        // }

        
        // return -1;

        if(nums.size()==1)return 0;
        

        vector<int>pref(nums.size()+1,0);
         long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pref[i]=sum;
        }

        for(int i=0;i<nums.size();i++){
            int left=0;
            if(i==0) left=0;
            else  left=pref[i-1];
            int right=pref[nums.size()-1]-pref[i];
            if(left==right)return i;
        }

        return -1;
    

        
        
        
    }
};