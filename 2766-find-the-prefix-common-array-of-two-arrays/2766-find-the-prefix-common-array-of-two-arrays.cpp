class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& arr, vector<int>& brr) {
        int n=arr.size();
        vector<int>ans(n, 0);
        set<int>a,b;
        int cnt=0;

        for (int i=0;i<n;++i) {
            
            if (a.find(brr[i])!=a.end()) {
                cnt++;
            }
            if (b.find(arr[i])!=b.end()) {
                cnt++;
            }
            if(arr[i]==brr[i])cnt++;
            ans[i] = cnt;
            a.insert(arr[i]);
            b.insert(brr[i]);

        }

        return ans;
    }
};
