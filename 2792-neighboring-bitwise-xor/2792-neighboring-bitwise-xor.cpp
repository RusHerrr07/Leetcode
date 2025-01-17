class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int val=accumulate(derived.begin(),derived.end(),0);
        return !(val&1);
        

        
    }
};