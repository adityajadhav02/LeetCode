class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i=3; i<=n; i++){
            for(int j = 1; j<i; j++){
                // Case 1 =  j & i-j are 2 nos that make up i
                // Case 2 = j & dp[j] are more than 2 components
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};