class Solution {
public:
    int solve(vector<int> &nums, int ind, int sum, vector<vector<int>> &dp){
        // base case
        if(ind==0){
            if(sum==0 && nums[0]==0) return 2;
            if(sum==0 || sum==nums[0]) return 1;
            return 0;
        }
        // if(sum == 0) return 1;
        
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int take = 0, notTake = 0;
        if(sum-nums[ind] >= 0) 
            take = solve(nums, ind-1, sum-nums[ind], dp);
        
        notTake = solve(nums, ind-1, sum, dp);
        
        return dp[ind][sum] = take+notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = 0;
        for(int i: nums) totSum += i;
        
        if(totSum-target<0 || ((totSum-target) %2 == 1)) return 0;
        int sum = (totSum-target)/2;
        
        // sum is the required subset sum
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(nums, n-1, sum, dp);
    }
};