/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* root){
        if(!root) return 0;
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    
    void dfs(TreeNode* root, vector<vector<int>> &ans, int depth){
        // base case
        if(!root) return;
        
        ans[depth].push_back(root->val);
        dfs(root->left, ans, depth-1);
        dfs(root->right, ans, depth-1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = getDepth(root);
        
        vector<vector<int>> ans(d, vector<int>(0));
        dfs(root, ans, d-1);
        return ans;
    }
};