class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
          
            int j=i+1;
            int k=n-1;

            while(j<k){
            long long sum=nums[i]+nums[j]+nums[k];
            if(sum==0  ){
                st.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;

            }
            else if(sum>0){
                k--;
            }
            else {
                j++;
            }
           

            }
           
        }

        for(auto i:st)
    {
        ans.push_back(i);
    }
    
       return ans; 
    }



};