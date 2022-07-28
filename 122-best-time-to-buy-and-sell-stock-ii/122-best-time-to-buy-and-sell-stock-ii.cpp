class Solution {
public:
    // Memoization
    // TC = O(n*2)
    // SC = O(n) + O(n*2)
    int solve(int ind, bool canBuy, vector<int> &prices, vector<vector<int>> &dp){
        // base case
        if(ind == prices.size()) return 0;
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        int profit = 0;
        if(canBuy){
            // buy & notBuy are profit after doing the corr. operations
            int buy = -prices[ind] + solve(ind+1, 0, prices, dp);
            int notBuy = solve(ind+1, 1, prices, dp);
            
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[ind] + solve(ind+1, 1, prices, dp);
            int notSell = solve(ind+1, 0, prices, dp);
            
            profit = max(sell, notSell);
        }
        return dp[ind][canBuy] = profit;
    }
    
    int solveTab(vector<int> &prices){
        vector<vector<int>> dp(prices.size()+1, vector<int> (2, 0));
        int n = prices.size();
        
        // base case
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind=n-1; ind>=0; ind--){
            for(int canBuy = 1; canBuy >=0; canBuy--){
                int profit = 0;
                if(canBuy){
                    // buy & notBuy are profit after doing the corr. operations
                    int buy = -prices[ind] + dp[ind+1][0];
                    int notBuy = dp[ind+1][1];

                    profit = max(buy, notBuy);
                }
                else{
                    int sell = prices[ind] + dp[ind+1][1];
                    int notSell = dp[ind+1][0];

                    profit = max(sell, notSell);
                }
                dp[ind][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
    
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        // return solve(0, 1, prices, dp);
        
        return solveTab(prices);
    }
};