class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        sort(nums.begin(),nums.end()); 
        
       st.insert(nums); 
        while(next_permutation(nums.begin(),nums.end())) st.insert(nums);
        vector<vector<int>>ans;
        for(auto &x:st){
            ans.push_back(x);
        }
        return ans;
    }
};
