class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0, j=n-1; i<n && j>=0; i++, j--)
            maxi = max(maxi, nums[i]+nums[j]);
        
        return maxi;
    }
};