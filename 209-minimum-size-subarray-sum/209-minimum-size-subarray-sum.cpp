class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
        int l=0, r=0, len = INT_MAX;
        int currSum = 0;
        while(r < nums.size()){
            currSum += nums[r++];
            
            // remove elements from start of window
            while(currSum >= target){
                currSum -= nums[l++];
                len = min(len, r-l+1);
            }
        }
        
        return len==INT_MAX ? 0 : len;
    }
};