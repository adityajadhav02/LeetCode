class Solution {
public:
    int solveTab(vector<int> &prices, int fee){
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
                    int sell = prices[ind] + dp[ind+1][1] - fee;
                    int notSell = dp[ind+1][0];

                    profit = max(sell, notSell);
                }
                dp[ind][canBuy] = profit;
            }
        }
        return dp[0][1];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        return solveTab(prices, fee);
    }
};