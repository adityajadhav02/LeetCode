class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n==2) return abs(nums[0]-nums[1]);
        
        int mini = nums[0];
        for(int i: nums)
            if(i < mini)
                mini = i;
        
        int ans = 0;
        for(int i : nums){
            if(i != mini)
                ans += abs(i - mini);
        }
        
        return ans;
    }
};