class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int>ans(n-k+1,-1);
    //    for(int i=0;i<=n-k;i++){
    //       int maxi=INT_MIN;
    //       for(int j=i;j<i+k;j++){
    //         maxi=max(maxi,nums[j]);
    //       }
    //        ans[i]=maxi;
        
    //    }
    //    return ans;

        int n=nums.size();
        int i=0;
        int j=0;
        vector<int>ans;
        set<pair<int,int>>st;
        while(j<n){
            st.insert({nums[j],j});
            if(j-i+1==k){
                auto val = *st.rbegin();
                ans.push_back(val.first);
                st.erase({nums[i],i});
                i++;
            }
            j++;
        }
        return ans;

      
        
    }
};