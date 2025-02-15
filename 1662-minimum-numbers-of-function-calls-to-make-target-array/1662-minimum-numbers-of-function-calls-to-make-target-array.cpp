class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        // O(nlog(max(nums[i],nums[i+1].......nums[n-1]))) time
        for(int i=0;i<nums.size();i++){
           auto val=nums[i];
           int x=0;
           while(val>0){
            
            if(val&1){
                val--;
                cnt1++;
            }
            else{
                val/=2;
                x++;
            }
            cnt2=max(cnt2,x);
           }
        }

        return cnt2+cnt1;
        
        
    }
}; 