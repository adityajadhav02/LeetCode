class Solution {
public:
    void dfs(int n, int k, int cur, int ind, int prev, vector<int> &ans){
        // base case
        if(ind == n-1){
            ans.push_back(cur);
            return;
        }
        int next = prev+k;
        if(next < 10)
            dfs(n, k, (cur*10)+next, ind+1, next, ans);
        
        next = prev-k;
        
        if(k!=0 && next>=0)
        dfs(n, k, (cur*10)+next, ind+1, next, ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            dfs(n, k, i, 0, i, ans);
        }
        return ans;
    }
};