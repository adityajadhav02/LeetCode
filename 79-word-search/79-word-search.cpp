class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board, string word){
        // base cases
        if(word.size()==0)
            return true;
        
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row]                            [col]!=word[0])
            return false;
        
        
        char c = board[row][col];
        board[row][col] = '.';
        string next = word.substr(1);
        
        bool check = solve(row+1, col, board, next) || solve(row-1, col, board, next) || solve(row, col+1, board, next) || solve(row, col-1, board, next);
        
        board[row][col] = c;
        return check;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(solve(row, col, board, word))
                    return true;
            }
        }
        return false;
    }
};