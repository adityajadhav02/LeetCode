class Solution {
public:
    int solveMem(string &t1, string &t2, int i, int j, vector<vector<int>> &dp){
        // base case
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // match
        if(t1[i] == t2[j])
            return dp[i][j] = 1+ solveMem(t1, t2, i-1, j-1, dp);
        
        return dp[i][j] = max(solveMem(t1, t2, i, j-1, dp), solveMem(t1, t2, i-1, j, dp));
    }
    
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solveMem(t1, t2, t1.size()-1, t2.size()-1, dp);
    }
};