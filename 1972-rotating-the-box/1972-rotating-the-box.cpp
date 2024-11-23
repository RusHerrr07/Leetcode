class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<char>> rotated(m,vector<char>(n));
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        rotated[j][n-1-i]=grid[i][j];
        for(int i=rotated.size()-1;i>=0;i--)
        for(int j=rotated[0].size()-1;j>=0;j--)
        if(rotated[i][j]=='.'){
            int row=i,col=j;
            while(row>=0&&rotated[row][col]!='*'){
                if(rotated[row][col]=='#'){
                    rotated[i][j]='#';
                    rotated[row][col]='.';
                    break;
                }
                row--;
            }
        }
        return rotated;
    }
};
