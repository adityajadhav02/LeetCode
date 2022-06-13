class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int> op, int k, int n){
        // base case
        if(ind > 9){
            if(n==0 && k==0){
                ans.push_back(op);
            }
            return;
        }
        
        if(ind <= n){
            op.push_back(ind);
            solve(ind+1, op, k-1, n-ind);
            op.pop_back();
        }
        solve(ind+1, op, k, n);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> op;
        
        solve(1, op, k, n);
        return ans;
    }
};