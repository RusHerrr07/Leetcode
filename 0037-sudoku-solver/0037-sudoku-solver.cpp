class Solution {

    bool isSafe(vector<vector<char>>& board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch || board[i][col]==ch || board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board,i,j,ch)){
                            board[i][j]=ch;
                            
                            if(solve(board,n)){
                                return true;
                            }
                            else
                            board[i][j]='.';
                            

                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        solve(board,n);
        
    }
};