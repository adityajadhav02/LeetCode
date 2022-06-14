class Solution {
public:
    
    
    int solve(int row, int col, int m, int n, vector<vector<int>>& grid){
        // base case
        if(row==m || row<0 || col==n || col<0 || grid[row][col]==0) 
            return 0;
        
        int start = grid[row][col];
        
        // mark visited
        grid[row][col] = 0;
        
        int maxi = 0;
        
        // go left
        maxi = max(maxi, solve(row, col-1, m, n, grid));
        
        // up
        maxi = max(maxi, solve(row-1, col, m, n, grid));
        
        // go right
        maxi = max(maxi, solve(row, col+1, m, n, grid));
        
        //down
        maxi = max(maxi, solve(row+1, col, m, n, grid));
        
        
        grid[row][col] = start;
        return maxi + start;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi = 0;
        int m = grid.size(), n = grid[0].size();
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                maxi = max(maxi ,solve(row, col, m, n, grid));
            }
        }
        return maxi;
    }
};