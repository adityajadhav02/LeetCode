class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // prefix products
        for(int i=1; i<n; i++)
            ans[i] = ans[i-1]*nums[i-1];
        
        // multiply with suffix
        int right = 1;
        for(int i = n-1; i>=0; i--){
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};