class Solution {
public:
    int solveMem(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        // base case
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // chars match
        if(s[i]==t[j]){
            int take = solveMem(s, t, i-1, j-1, dp);
            int notTake = solveMem(s, t, i-1, j, dp);
            return dp[i][j] = take + notTake;
        }
        
        else
            return dp[i][j] = solveMem(s, t, i-1, j, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solveMem(s, t, n-1, m-1, dp);
    }
};