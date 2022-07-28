class Solution {
public:
    int solveTab(vector<int> &prices, int k){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, 
                                       vector<vector<int>>(2, vector<int> (k+1, 0)));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int canBuy = 0; canBuy<=1; canBuy++){
                for(int cap=1; cap<=k; cap++){
                    int profit = 0;
                    if(canBuy){
                        int buy = -prices[ind] + dp[ind+1][0][cap];
                        int notBuy = dp[ind+1][1][cap];
                        profit = max(buy, notBuy);
                    }
                    else{
                        int sell = prices[ind] + dp[ind+1][1][cap-1];
                        int notSell = dp[ind+1][0][cap];
                        profit = max(sell, notSell);
                    }
                    dp[ind][canBuy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        return solveTab(prices, k);
    }
};