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
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        // return solve(grid, r-1, c-1);
        
        vector<vector<int>> dp(r, vector<int> (c, -1));
        return solveMem(grid, r-1, c-1, dp);
    }
};