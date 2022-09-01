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
    vector<int> in;
    int index = 0;
    void inorder(TreeNode* root){
        // base case
        if(!root)  return;
        
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    void updateTree(TreeNode* root){
        // base case
        if(!root) return;
        
        updateTree(root->left);
        root->val = in[index];
        index += 1;
        updateTree(root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        
        for(int i= in.size()-2; i>=0; i--)
            in[i] += in[i+1];
                
        updateTree(root);
        return root;
    }
};