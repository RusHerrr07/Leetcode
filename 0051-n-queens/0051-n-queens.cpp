class Solution {

    bool isSafe(vector<string>&board,int row,int col,int n){
        int duprow=row;int dupcol=col;
        row=row-1;
        col=col-1;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        

        row=duprow;
        col=dupcol;
        row+=1;
        col-=1;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }

        row=duprow;
        col=dupcol;
        
        col-=1;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
          
            col--;
        }



        return true;

        



    }
   vector<vector<string>>ans;
   void solve(vector<string>&board,int col,int n){
    if(col==n){
        ans.push_back(board);
        return ;
    }

    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(board,col+1,n);
            board[row][col]='.';
            
        }
    }
   }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
        
    }
};