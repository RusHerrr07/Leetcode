class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int>st;
        int n=nums.size();
        int i=0;
        long long maxi=LLONG_MIN;
        long long sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(st.find (nums[j])!=st.end()){
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            st.insert(nums[j]);
            if(st.size()==k && j-i+1==k){
                maxi=max(sum,maxi);
                st.erase(nums[i]);
                sum-=nums[i];
                i++;


            }

        }

        return maxi==LLONG_MIN ? 0:maxi;
        
    }
};