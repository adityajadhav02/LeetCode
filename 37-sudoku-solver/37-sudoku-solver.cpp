class Solution {
public:
    bool isSafe(int row, int col, char val, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            // row check
            if(board[row][i] == val)
            return false;
            
            // col check
            if(board[i][col] == val)
            return  false;
            
            // matrix check
            if(board[3*(row/3) +i/3][3*(col/3) + i%3] == val)
            return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] == '.'){
                    for(int i=1; i<=9; i++){
                        if(isSafe(row, col , i+'0', board)){
                            board[row][col] = (char)(i+'0');
                            bool isPossible = solve(board);
                            if(isPossible)
                                return true;
                            
                            else
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};