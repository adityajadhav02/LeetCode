class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(int i: nums)
            totalSum += i;
        
        // select largest subarrray with sum = totalSum-x
        int targetSum = totalSum - x;
        if(targetSum == 0)
            return nums.size();
        
        int j, i=0, len = 0;
        int currSum = 0;
        for(j=0; j<nums.size(); j++){
            currSum += nums[j];
            
            // remove elements from start of window
            while(i<nums.size() && currSum > targetSum){
                currSum -= nums[i++];
            }
            
            if(currSum == targetSum)
                len = max(len, j-i+1);  //for largest subarray
        }
        
        // no such subarray found
        if(!len)
            return -1;
        
        return nums.size()-len;
    }
};