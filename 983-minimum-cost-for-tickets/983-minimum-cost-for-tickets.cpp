class Solution {
public:
    int solve(vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
        int n = days.size();
        // base case
        if(index >= n) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        //1 day pass
        int op1 = costs[0] + solve(days, costs, index+1, dp);
        
        // 7 day pass
        int i;
        for(i = index; i<n && days[i] < days[index]+7; i++);
        int op2 = costs[1] + solve(days, costs, i, dp);
        
        // 30 day pass
        for(i = index; i<n && days[i] < days[index]+30; i++);
        int op3 = costs[2] + solve(days, costs, i, dp);
        
        dp[index] = min({op1, op2, op3});
        return dp[index];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return solve(days, costs, 0, dp);
    }
};