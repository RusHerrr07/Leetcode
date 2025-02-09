class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        /*
        int n=nums.size();
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(j-i !=nums[j]-nums[i])cnt++;
            }
        }
        return cnt;
        */
        int n=nums.size();
        long long total=1LL*n*(n-1)/2;
        // set<int>st;
        long long good=0;
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
            good+=mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        

        return total-good;

       
     
        
    }
};