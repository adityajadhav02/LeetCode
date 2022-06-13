class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int> &arr, vector<int> &op, int target){
        // base case
        if(ind == arr.size()){
            if(target==0){
                ans.push_back(op);
            }
            return;
        }
        
        if(arr[ind] <= target){
            op.push_back(arr[ind]);
            solve(ind, arr, op, target-arr[ind]);
            op.pop_back();
        }
        solve(ind+1, arr, op, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> op;
        solve(0, arr, op, target);
        
        return ans;
    }
};