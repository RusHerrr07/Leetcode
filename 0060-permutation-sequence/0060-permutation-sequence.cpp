class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        // vector<int>ans;
        k--;
        while(k>0){
            next_permutation(arr.begin(), arr.end());
            k--;

        }
        string ans="";
        for(auto &val:arr){
            ans+=to_string(val);
        }
        return ans;
        
    }
};