class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //   sort(nums.begin(),nums.end());
        // int left=0;
        // int right=nums.size()-1;
        // int cnt=0;
        // while(right>left){
        //     long long sum=nums[left]+nums[right];
        //     if(sum==k){
        //         cnt++;
        //         left++;
        //         right--;
        //     }
        //     else if(sum<k)left++;
        //     else right--;

        // }

        // return cnt;


        
        
        
        
        
        map<int,int>mp;
        int cnt=0;
   
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem=k-nums[i];
            if(mp.count(rem)){
                cnt++;
                --mp[rem];
                if(mp[rem]==0)mp.erase(rem);
            }
            else
            mp[nums[i]]++;
            
        }
        return cnt;
      


        
    }
};