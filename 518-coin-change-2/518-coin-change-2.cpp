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
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};