class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
          int left = 0, right = m - 1, top = 0, down = n - 1;
        int dir=0;
        vector<int>ans;
        while(left<=right && top<=down){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);

                }
                top++;
            }
            else if( dir==1){
                for(int i=top ;i<=down ;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }

            else if(dir==3) {

                for(int i=down;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;

            }

            dir++;
            if(dir==4){
                dir=0;
            }

        }
        return ans;
        
    }
};