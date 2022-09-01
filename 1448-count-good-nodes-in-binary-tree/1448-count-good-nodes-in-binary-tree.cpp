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
    int cnt = 0;
    void dfs(TreeNode* root, int maxi){
        // base case
        if(!root) return;
        
        if(root->val >= maxi){
            cnt++;
            maxi = max(maxi, root->val)
;        } 
        // int newMaxi = max(maxi, root->val);
        dfs(root->left, maxi);
        dfs(root->right, maxi);   
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return cnt;
    }
};