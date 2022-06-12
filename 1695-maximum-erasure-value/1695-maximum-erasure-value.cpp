class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int left = 0, right = 0;
        int currSum = 0, ans = 0;
        
        while(right < nums.size()){
            while(s.find(nums[right]) != s.end()){
                currSum -= nums[left];
                s.erase(nums[left++]);
            }
            
            currSum += nums[right];
            s.insert(nums[right++]);
            
            ans = max(ans, currSum);
        }
        return ans;
    }
};