class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, -1);
        vector<int> mp(nums.size()+1, 0);
        for(int i: nums)
            mp[i]++;
        
        for(int i=1; i<mp.size(); i++){
            if(mp[i] == 2) ans[0] = i;
            if(mp[i] == 0) ans[1] = i;
        }
        return ans;
    }
};