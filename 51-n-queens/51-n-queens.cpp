class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(int row, int col, vector<string> &board){
        int x = row, y=col;
        // row check
        while(y>=0){
            if(board[x][y]=='Q')
                return false;
            y--;
        }
        
        // upper diagonal check
        x = row, y = col;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q')
            return false;
            
            y--;
            x--;
        }
        
        // lower diag check
        x = row, y = col;
        while(x<board.size() && y>=0){
            if(board[x][y] == 'Q')
            return false;
            
            y--;
            x++;
        }
        
        return true;
    }
    
    void solve(int col, vector<string> &board){
        // base case
        if(col == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<board.size(); row++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                solve(col+1, board);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board);
        return ans;
    }
};