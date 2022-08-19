class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // using prefix sum
        
        unordered_map<int, int> mp;
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            prefix[i] = nums[i]+prefix[i-1];
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(prefix[i] == k) ans++;
            
            int diff = prefix[i]-k;
            // if(mp.find(diff) != mp.end()) ans += mp[diff];
            if(mp[diff] > 0) ans += mp[diff];
            
            mp[prefix[i]]++;
        }
        return ans;
    }
};