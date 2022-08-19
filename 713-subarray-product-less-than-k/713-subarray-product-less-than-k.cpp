class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, prod = 1;
        int ans = 0;
        
        if(k <= 1) return 0;
        
        while(right < nums.size()){
            prod *= nums[right];
            
            while(prod >= k){
                prod /= nums[left];
                left++;
            }
            
            // no. of new subarrays introduced
            ans += right - left + 1;
            right ++;
        }
        return ans;
    }
};