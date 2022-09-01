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
    int sum = 0;
    void getChildSum(TreeNode* root){
        if(!root) return;
        if(root->left) sum += root->left->val;
        if(root->right) sum += root->right->val;
    }
    
    void solve(TreeNode* root){
        // base case
        if(!root) return;
        
        if(root->val %2 == 0){
            getChildSum(root->left);
            getChildSum(root->right);
        }
        
        solve(root->left);
        solve(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root);
        return sum;
    }
};