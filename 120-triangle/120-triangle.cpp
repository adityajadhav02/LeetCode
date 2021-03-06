class Solution {
public:
    int findMinPath(vector<vector<int>>& triangle, int row, int col){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // base case
        // initialise last row elements same as in triangle
        for(int j=0; j<n; j++)
            dp[n-1][j] = triangle[n-1][j];
        
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                
                int down = triangle[i][j] + dp[i+1][j];
                int downDiag = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, downDiag);
            }
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return findMinPath(triangle, 0, 0);
    }
};