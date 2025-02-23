class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        
        long long maxi=0;
        vector<int> arr;

        for(int i=0;i<grid.size();i++){
            int lim=limits[i];
            auto& row=grid[i];
            sort(row.begin(),row.end(),greater<int>());
            
            for(int j=0;j<lim;j++){
                arr.push_back(row[j]);
            }
        }

        sort(arr.begin(),arr.end(),greater<int>());

        for(int i=0;i<k;i++){
            maxi+=arr[i];
        }

        return maxi;
    }
};