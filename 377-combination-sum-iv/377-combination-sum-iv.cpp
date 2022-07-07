class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1, 0);
        
        dp[0] = 1;
        
        // fill dp for each target
        for(int i=1; i<=target; i++){
            
            // traverse nums
            for(int j=0; j<nums.size(); j++){
                if(i-nums[j] >=0 )
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};