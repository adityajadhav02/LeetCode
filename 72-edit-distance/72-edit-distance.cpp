class Solution {
public:
    int solve(string &w1, string &w2, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        // match
        if(w1[i] == w2[j]){
            return dp[i][j] = solve(w1, w2, i-1, j-1, dp);
        }
        
        else{
            int insertOp = 1 + solve(w1, w2, i, j-1, dp);
            int deleteOp = 1 + solve(w1, w2, i-1, j, dp);
            int replaceOp = 1 + solve(w1, w2, i-1, j-1, dp);
            
            return dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
        }
    }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(w1, w2, n-1, m-1, dp);
    }
};