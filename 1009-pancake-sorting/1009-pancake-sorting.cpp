class Solution {
private:
    bool isSorted(vector<int>& a) {
        for(int i = 1; i < a.size(); i++) {
            if(a[i] < a[i-1]) return false;
        }
        return true;
    }

public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        
        if(isSorted(arr)) return ans; 
        
        bool flag = false;
        if(arr[n-1] == n) {
            flag = true;
        }
        
        if(!flag) {
            for(int i = 0; i < n; i++) {
                if(arr[i] == n) {
                    reverse(arr.begin(), arr.begin() + i + 1);
                    ans.push_back(i + 1);
                    break;
                }
            }
            reverse(arr.begin(), arr.begin() + n);
            ans.push_back(n);
        }
        
        int val = n - 1;
        int idx = n - 2;
        
        while(idx >= 0) {
            if(arr[idx] == val) {
                idx--;
                val--;
            }
            else {
                for(int i = 0; i < n; i++) {
                    if(arr[i] == val) {
                        reverse(arr.begin(), arr.begin() + i + 1);
                        ans.push_back(i + 1);
                        break;
                    }
                }
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);
            }
        }

        for(auto &i:arr){
            cout<<i<<" ";
        }
        
        return ans;
    }
};
