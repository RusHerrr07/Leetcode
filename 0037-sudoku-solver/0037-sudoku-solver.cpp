class Solution {
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }

    private:
    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        for(int i=0; i<9; i++) {
            if(board[i][col] == c || board[row][i] == c || board[3*(row/3) + i/3][3*(col/3) + i%3] == c) {
                return false;
            }
        }
        return true;

    }



bool solve( vector<vector<char>>&board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                     if(isSafe(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.'; 
                            }
                        }
                }
                return false;
            }

            
        }

    }

    return true;
}
};