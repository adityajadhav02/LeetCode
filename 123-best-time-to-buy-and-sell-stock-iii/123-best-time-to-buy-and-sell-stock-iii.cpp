class Solution {
public:
    
    // TC = O(n*2*3)
    // SC = O(n) + O(n*2*3)
    int solve(int ind, int canBuy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        // base case
        if(ind==prices.size() || cap==0) return 0;
        
        
        if(dp[ind][canBuy][cap] != -1) return dp[ind][canBuy][cap];
        int profit = 0;
        if(canBuy){
            int buy = -prices[ind] + solve(ind+1, 0, cap, prices, dp);
            int notBuy = solve(ind+1, 1, cap, prices, dp);
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[ind] + solve(ind+1, 1, cap-1, prices, dp);
            int notSell = solve(ind+1, 0, cap, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][canBuy][cap] = profit;
    }
    
    
    // TC = O(n*2*3)
    // SC = O(n*2*3)
    int solveTab(vector<int> &prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, 
                                       vector<vector<int>>(2, vector<int> (3, 0)));
        
        for(int ind=n-1; ind>=0; ind--){
            for(int canBuy = 0; canBuy<=1; canBuy++){
                for(int cap=1; cap<=2; cap++){
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
        return dp[0][1][2];
    }
    
    
    int maxProfit(vector<int>& prices) {
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int> (3, -1)));
        
        // return solve(0, 1, 2, prices, dp);
        
        return solveTab(prices);
    }
};