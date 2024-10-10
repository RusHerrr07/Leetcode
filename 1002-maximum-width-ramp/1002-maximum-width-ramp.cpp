class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        /*
        Brute force-->o(n^2) time-->

        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>=nums[i]){
                    maxi=max(maxi,j-i);
                }
            }
        }
        return maxi;

        */

      
        /*Radhe Radhe*/

        //optimal o(n) time and space
       int n=nums.size();
        int ans=0;
        vector<int> suff(n,0);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            suff[i]=max(nums[i],suff[i+1]);
        }
        int l=0,r=0;
        while(r<n) {
            while(l<r && suff[r]<nums[l]) {
                l++;
            }
            ans=max(ans,r-l);
            r++;
        }
        return ans;
        

        

        
    }
};