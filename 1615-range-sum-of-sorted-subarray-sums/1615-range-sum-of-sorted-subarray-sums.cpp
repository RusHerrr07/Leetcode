class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
      
        vector<long long >arr;
        long long sum=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                sum+=nums[j];
                    arr.push_back(sum);
                  
            }
        sum=0;
        }

        sort(arr.begin(),arr.end());
        left--;
        right--;
       
        sum=0;


        for(int i=left ;i<=right;++i){
             sum+=arr[i];
        }
        int MOD = 1000000007;
        return sum% MOD;    
    }
};