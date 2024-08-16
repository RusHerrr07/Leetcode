class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int max_dist = 0;
        
        for (int i = 1; i < arrays.size(); ++i) {  
            int first = maxi - arrays[i][0];
            int sec = arrays[i].back() - mini;

            max_dist = max(max_dist, max(first, sec)); 
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }

        return max_dist;
    }
};
