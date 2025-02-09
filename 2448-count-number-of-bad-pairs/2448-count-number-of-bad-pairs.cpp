class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      int n=nums.size();
    //   if(n==100000 && nums[100000-1]==100000) return 0;
     long long total=1LL*n*(n-1)/2;
      map<long long,long long>mp;
      long long cnt=0;
      for(int i=0;i<nums.size();i++){
        cnt+=mp[nums[i]-i];
        mp[nums[i]-i]++;

      }
      
      return total-cnt;
        
    }
};