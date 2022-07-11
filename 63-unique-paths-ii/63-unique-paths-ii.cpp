class Solution {
public:
    int solveTab(int row, int col, vector<vector<int>>& arr){
        vector<vector<int>> dp(row, vector<int> (col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j] == 1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;

                else{
                    int left=0, up=0;
                    if(j>0) 
                        left = dp[i][j-1];
                    if(i>0)
                        up = dp[i-1][j];
                    dp[i][j] = (up + left);
                }
            }
        }
        return dp[row-1][col-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        return solveTab(arr.size(), arr[0].size(), arr);
    }
};