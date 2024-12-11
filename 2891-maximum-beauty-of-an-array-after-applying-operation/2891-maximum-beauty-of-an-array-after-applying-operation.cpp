class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=0;
        int i=0;
        int j=0;
        while(j<n){
            while(j<n && nums[j]-nums[i]<=2*k){
                j++;
                maxi=max(maxi,j-i);
            }
            i++;
        }
        return maxi;
        
    }
};