class Solution {
public:
    void solve(vector<int> &nums, vector<int> op, int ind, vector<vector<int>> &ans){
        // base case
        if(ind<0){
            ans.push_back(op);
            return;
        }
        
        // include
        op.push_back(nums[ind]);
        solve(nums, op, ind-1, ans);
        op.pop_back();
        // exclude
        solve(nums, op, ind-1, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        
        solve(nums, op, nums.size()-1, ans);
        return ans;
    }
};