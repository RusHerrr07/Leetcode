class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        map<int,int>mp;
        int i=0;
        int j=0;
        int n=nums.size();
        long long cnt=0;
        long long ans=0;
        while(j<n){
            mp[nums[j]]++;
           cnt+=(mp[nums[j]]-1);

            while(cnt>=k){
                ans+=(n-j);
                if(mp[nums[i]]>=2){
                    cnt-=(mp[nums[i]]-1);

                }
                mp[nums[i]]--;
                i++;
            }
            j++; 
        }
        return ans;
    }
};
