class Solution {
public:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(ind == coins.size()) return 0;
        if(amount == 0) return 1;
        
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int take = 0;
        if(amount - coins[ind] >= 0)
            take = solve(ind, amount-coins[ind], coins, dp);
        
        int notTake = solve(ind+1, amount, coins, dp);
        return dp[ind][amount] = take+notTake;
    }
    
    int solveTab(int amount, vector<int> &coins){
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        
        // base case
        for(int i=0; i<n; i++)
            dp[i][0] = 1;
        
        for(int ind=n-1; ind>=0; ind--){
            for(int amt = 1; amt<=amount; amt++){
                int take = 0;
                if(amt - coins[ind] >= 0)
                    take = dp[ind][amt-coins[ind]];

                int notTake = dp[ind+1][amt];
                dp[ind][amt] = take+notTake;
            }
        }
        return dp[0][amount];
    }
    int change(int amount, vector<int>& coins) {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        // return solve(0, amount, coins, dp);
        
        return solveTab(amount, coins);
    }
};