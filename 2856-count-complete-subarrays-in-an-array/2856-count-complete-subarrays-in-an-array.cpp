class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        
        int k = st.size();
        st.clear();
        int cnt = 0;
        int n = nums.size();
        int i=0;int j=0;
        map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            if(mp.size()==k){
                while(mp.size()==k){
                    cnt=cnt+(n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
            }
            j++;


        }

        
        
        return cnt;
    }
};
