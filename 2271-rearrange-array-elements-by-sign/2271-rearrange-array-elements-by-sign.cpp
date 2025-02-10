class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        deque<int>pos,neg;
        vector<int>ans;
        int n =nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]>0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }
        while(!neg.empty()&&!pos.empty()) {
            ans.push_back(pos.front());
            ans.push_back(neg.front());
            pos.pop_front();
            neg.pop_front();
        }
    
        
        return ans;
    }
};