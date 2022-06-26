class Solution {
public:
    int solve(vector<int> cost, int n){
        // base case
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
    
    int solve2(vector<int> cost, int n, vector<int> &dp){
        // base case
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        // check if present in dp
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        return dp[n];
    }
    
    // Tabulation => 
    int solve3(vector<int> &cost, int n){
        
        // Create dp array
        vector<int> dp(n+1, -1);
        
        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        return min(dp[n-1], dp[n-2]);
    }
    
    int solve4(vector<int> &cost, int n){
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // Simple recursion
        // int ans = min(solve(cost, n-1), solve(cost, n-2));
        // return  ans;
        
        // Recursion + Memoization
        // vector<int> dp(n+1, -1);
        // int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
        // return ans;
        
        // Tabulation
        //return solve3(cost, n);
        
        // Space Optimised
        return solve4(cost, n);
    }
};