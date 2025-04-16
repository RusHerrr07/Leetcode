class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        for(auto &arr:queries){
            int row1=arr[0];
            int col1=arr[1];
            int row2=arr[2];
            int col2=arr[3];
            for(int i=row1;i<=row2;i++){
                grid[i][col1]+=1;
                if(col2+1<n)
                grid[i][col2+1]-=1;
            }
            
        }

        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=grid[i][j]+grid[i][j-1];
            }
        }

        return grid;
        
        
        
    }
};