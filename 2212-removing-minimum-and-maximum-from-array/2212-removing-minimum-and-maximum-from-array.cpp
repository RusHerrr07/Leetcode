class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
      int n=nums.size();
int k=0,i=0,j=0;
int mini=*min_element(begin(nums),end(nums));
int maxi=*max_element(begin(nums),end(nums));
if(n<=2){
    return n;
}
while(i<n){
    if(nums[i]!=mini && nums[i]!=maxi){
        j=i;
        while(j<n && nums[j]!=mini && nums[j]!=maxi){
            k=max(k,j-i+1);
            j++;
        }
        i=j;
    } else {
        i++;
    }
}
return k==0 ? 0 : n-k;

        
      
    }
};