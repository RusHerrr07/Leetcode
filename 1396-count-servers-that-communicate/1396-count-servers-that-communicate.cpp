class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int  n=grid.size();
        int m=grid[0].size();
        map<int,int>mp1,mp2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mp1[i]++;
                    mp2[j]++;
                }
            }
        }
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((mp1[i]>=2 || mp2[j]>=2) && grid[i][j]==1){
                    ans++;
                }
            }
        }


            return ans;
        
    }
};