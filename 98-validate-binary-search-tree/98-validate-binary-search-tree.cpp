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
    bool solve(TreeNode* root, TreeNode* mini, TreeNode* maxi){
        // base case
        if(!root) return true;
        
        int data = root->val;
        if((mini && root->val<=mini->val) || (maxi && root->val >= maxi->val)) return false;
        
        return solve(root->left, mini, root) && solve(root->right, root, maxi);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, NULL, NULL);
    }
};