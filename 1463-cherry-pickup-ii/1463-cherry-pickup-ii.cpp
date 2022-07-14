class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>>&dp){
        int r = grid.size();
        int c = grid[0].size();
        
        // base case
        if(j1<0 || j2<0 || j1>=c || j2>=c) return -1e8;
        if(i == r-1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        //explore all paths
        long long maxi = -1e8;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                long long val = 0;
                if(j1 == j2) val = grid[i][j1];
                
                else
                    val = grid[i][j1] + grid[i][j2];
                
                val += solve(grid, i+1, j1+dj1, j2+dj2, dp);
                maxi = max(maxi, val);
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int> (c, -1)));
        return solve(grid, 0, 0, c-1, dp);
    }
};