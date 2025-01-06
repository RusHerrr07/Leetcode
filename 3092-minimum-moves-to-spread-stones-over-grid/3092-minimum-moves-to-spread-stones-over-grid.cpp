class Solution {
public:
    int solve(vector<pair<int,int>>& arr1 , vector<pair<int,int>>& arr2 , int ind ,vector<vector<int>>& grid ){
        if(ind == arr2.size())return 0;
        
        int res = INT_MAX;
        for(auto [i,j]:arr1){
            if(grid[i][j] > 1){
                int d = abs(i - arr2[ind].first) + abs(j- arr2[ind].second);
                grid[i][j] --;
                res = min(res, d+solve(arr1, arr2, ind+1, grid));
                grid[i][j] ++;
            }
        }
        
        return res;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        
        vector<pair<int,int>> arr1;
        vector<pair<int,int>> arr2;
        
       for(int i =0;i<3;i++){
           for(int j=0;j<3;j++){
               if(grid[i][j] >1 )arr1.push_back({i,j});
               if(grid[i][j] == 0 )arr2.push_back({i,j});
           }
       }
        
        return solve(arr1, arr2,0 ,grid);
    
    }
};