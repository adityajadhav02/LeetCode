class Solution {
public:
    int ans = 0;
    
    bool isSafe(int row, int col, vector<string> &board, int n){
        int x=row, y=col;
        // row check
        while(y>=0){
            if(board[x][y]=='Q')
                return false;
            
            y--;
        }
        
        // upper diag check
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y] =='Q')
                return false;
            
            x--;
            y--;
        }
        
        // lower diag check
        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y] =='Q')
                return false;
            
            x++;
            y--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &board, int n){
        // base case
        if(col == n){
            ans++;
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        solve(0, board, n);
        return ans;
    }
};