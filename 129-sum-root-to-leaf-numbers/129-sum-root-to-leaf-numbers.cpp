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
    int ans=0;
    string s;
    void solve(TreeNode* root){
        // base case
        if(!root) return ;
        
        s += to_string(root->val);
        
        // got a leaf node
        if(!root->left && !root->right){
            ans += stoi(s);
            s.pop_back();
            return;
        }
        
        solve(root->left);
        solve(root->right);
        s.pop_back();
        return ;
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root);
        return ans;
    }
};