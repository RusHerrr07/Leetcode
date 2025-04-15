class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int>st(nums.begin(),nums.end());
       nums.clear();
       for(auto &i:st){
         nums.push_back(i);
         cout<<i<<" ";
       }
       if(nums.size()<=1) return nums.size();
       int maxi=1;
       int idx=0;
       while(idx<nums.size()){
        int val=nums[idx];
        int cnt=0;
        if(nums[idx]==val){
            while(idx<nums.size() && val==nums[idx]){
            val++;
            cnt++;
            idx++;
        }
        maxi=max(cnt,maxi);

        }
        else{
            idx++;
        }
        
        
        

        
       }
       return maxi;

        
    }
};