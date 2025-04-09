// why this solution is failed--->
// while -->strength-->[7,3,6,18,22,50] and k=4;

// class Solution {
// public:
//     int findMinimumTime(vector<int>& arr, int k) {
//         int n = arr.size();
//         int energy = 0;
//         int factor = 1;
//         int time = 0;

//         while (true) {
//             energy += factor;
//             sort(arr.begin(), arr.end());
//             bool flag = true;
//             for (int i = 0; i < n; i++) {
//                 if (arr[i] != -1) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag) {
//                 return time;
                
//             };

//             for (int i = n - 1; i >= 0; i--) {
//                 if (arr[i] != -1 && energy >= arr[i]) {
//                     energy = 0;
//                     arr[i] = -1;
//                     factor += k;
//                     break;
//                 }
//             }

//             time++;
//         }

//         return time;
//     }
// };





class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int result = INT_MAX;
        int count = 0;
        solve(strength, k, count, result, 0, 1);
        return result;
    }
    void solve(vector<int>& strength, int& k, int cnt, int& ans, int t, int x){
        if(t>ans) return;
        if(cnt==strength.size()){
            ans = min(ans, t);
            return;
        }     
        int n = strength.size();
        for(int i=0; i<n; i++){
            if(strength[i]!=-1){
                int tmp = strength[i];
                int inc = strength[i]/x+(strength[i]%x>0? 1:0);
                strength[i] = -1;
                solve(strength, k, cnt+1, ans, t+inc, x+k);
                strength[i] = tmp;
            }
        }
        return;
    }
};
