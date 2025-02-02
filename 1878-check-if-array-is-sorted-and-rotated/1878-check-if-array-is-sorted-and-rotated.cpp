class Solution {
public:
    bool check(vector<int>& nums) {
//    int n=nums.size();
//    int cnt=0;

//     for(int i=1;i<n;i++){
//         if(nums[i-1]>nums[i])cnt++;
//     }

//edges case----->

//     if(nums[n-1]>nums[0])cnt++;
//        return cnt<=1;


//from here-->An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

  int n=nums.size();
   int cnt=0;
    for (int i=0;i<n; i++) 
        if(nums[i]>nums[(i+1)%n])cnt++;
       return cnt<=1;




        
    }
};