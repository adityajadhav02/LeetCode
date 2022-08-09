class Solution {
public:
    int check(vector<vector<int>> &grid, int r, int c){
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto d : dir){
            int x = r+d[0], y=c+d[1];
            if(x<0 || y<0 || x==n || y==m || grid[x][y]==0)
                ans++;
        }
        return ans;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                ans += check(grid, i, j);
            }
        }
        return ans;
    }
};