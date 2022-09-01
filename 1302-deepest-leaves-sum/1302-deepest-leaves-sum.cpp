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
    int maxDepth=0;
    int sum = 0;
    void solve(TreeNode* root, int depth){
        // base case
        if(!root) return;
        
        // if leaf
        if(!root->left && !root->right){
            if(depth == maxDepth) sum += root->val;
            if(depth > maxDepth){
                sum = root->val;
                maxDepth = depth;
            } 
        }
        
        solve(root->left, depth+1);
        solve(root->right, depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        solve(root, 0); 
        return sum;
    }
};