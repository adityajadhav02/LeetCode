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
    void inorder(TreeNode* root, vector<int> &in){
        // base case
        if(!root) return;
        
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1, in2;
        inorder(root1, in1);
        inorder(root2, in2);
        
        vector<int> ans;
//         set<int> s;
//         for(int i: in1) s.insert(i);
//         for(int i: in2) s.insert(i);
        
        for(auto i: in1) ans.push_back(i);
        for(auto i: in2) ans.push_back(i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};