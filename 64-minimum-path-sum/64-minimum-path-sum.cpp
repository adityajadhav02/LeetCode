class Solution {
public:
    // TC = O(2^(rc))
    // SC = O(Path len)
    int solve(vector<vector<int>>& grid, int r, int c){
        // base case
        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return 1e9;
        
        int up = grid[r][c] + solve(grid, r-1, c);
        int left = grid[r][c] + solve(grid, r, c-1);
        
        return min(up, left);
    }
    
    // TC = O(rc)
    // SC = O(Path len) + O(rc)
    int solveMem(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp){
        // base case
        if(r==0 && c==0) return grid[0][0];
        if(r<0 || c<0) return 1e9;
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int up = grid[r][c] + solveMem(grid, r-1, c, dp);
        int left = grid[r][c] + solveMem(grid, r, c-1, dp);
        
        return dp[r][c] = min(up, left);
    }
    
    int solveTab(vector<vector<int>>& grid){
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> dp(r, vector<int> (c, 0));
        
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                
                int up = 1e9, left = 1e9;
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                
                else {
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];
        
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[r-1][c-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        // return solve(grid, r-1, c-1);
        
        // vector<vector<int>> dp(r, vector<int> (c, -1));
        // return solveMem(grid, r-1, c-1, dp);
        
        return solveTab(grid);
    }
};