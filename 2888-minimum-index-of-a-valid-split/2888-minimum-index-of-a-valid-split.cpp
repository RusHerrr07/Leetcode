class Solution {
private:
    set<int> left, right;

    void countDominantsInRange(vector<int>& arr, int l, int r) {
        right.clear();
        unordered_map<int, int> freq;
        for (int i = l; i <= r; i++) freq[arr[i]]++;

        int rangeSize = r - l + 1;
        for (auto &[val, cnt] : freq) {
            if (cnt * 2 > rangeSize) right.insert(val);
        }
    }

public:
    int minimumIndex(vector<int>& nums) {

 // int ans = -1;
 //        int n = nums.size();
 //        // int start = 0;
 //        // int end = n - 1;
 //        // while (start <= end) {
 //        //     int mid = (start + end) / 2;
 //        //     int val1 = countDominantsInRange(nums, 0, mid);
 //        //     int val2 = countDominantsInRange(nums, mid + 1, n - 1);
 //        //     if (val1 == val2) {
 //        //         start = mid + 1;
 //        //         ans = mid;
 //        //     } else {
 //        //         end = mid - 1;
 //        //     }
 //        // }
 //        // return ans;

 //        countDominantsInRange(nums,0,n-1);

 //        set<int>left,right;
        
 //        map<int,int>mp;
 //        for(auto &val:nums){
 //            mp[val]++;
 //        }
 //        map<int,int>curr;
 //        for(int i=0;i<nums.size()-1;i++){
 //            curr[nums[i]]++;
 //            int all=mp[nums[i]];
 //            int val=curr[nums[i]];
 //            if(val*2>(i+1)){
 //                left=insert(nums[i]);  
 //            }
 //            all-=val;
 //            if(all<=(n-i+1)){
 //                if(right.find(nums[i])!=right.end()){
 //                    right.erase(nums[i]);
 //                }
 //            }
 //            if(left.size()==right.size()){
 //                return i;
 //            }
            
 //        }

 //        return -1;
        int ans = -1;
        map<int, int> mp;
        for (auto &value : nums) {
            mp[value]++;
        }
        map<int, int> curr;
        for (int i = 0; i < nums.size() - 1; i++) {
            curr[nums[i]]++;
            int val1 = curr[nums[i]];
            int val2 = mp[nums[i]] - val1;

            if (val1 * 2 > i + 1 && val2 * 2 > nums.size() - i - 1) {
                return i;
            }
        }
        return -1;
    }
};
