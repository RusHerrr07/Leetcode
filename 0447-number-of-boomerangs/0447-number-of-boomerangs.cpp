class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        map<int, int> mp;
        for(int i=0; i<points.size() ; i++){
            for(int j=0 ; j<points.size() ; j++){
                int d = pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2);
                ans += 2 * mp[d]++;
            }
            mp.clear();
        }
        return ans;
    }
    
};