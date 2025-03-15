class Solution {
private:
bool isValid(vector<int>&nums,int mid,int k){
    int n=nums.size();
     int idx=0;
    int cnt=0;
    while(idx<n){
        if(nums[idx]<=mid){
            cnt++;
            idx++;
        }
        if(cnt>=k)return true;
            idx++;
    }
    return false;
}
public:
    int minCapability(vector<int>& nums, int k) {
        int ans=-1;
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        while(high>=low){
            int mid=(low+high)/2;
            if(isValid(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};