class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int diff = sum-k;
            if(mp[diff] > 0)
            ans += mp[diff];
            
            mp[sum]++;
        }
        return ans;
    }
};