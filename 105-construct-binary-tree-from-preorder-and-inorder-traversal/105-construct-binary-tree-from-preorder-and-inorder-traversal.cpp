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
    unordered_map<int, int> mp;
    
    TreeNode* solve(vector<int> &preorder, int &index, int startInd, int endInd){
        // base case
        if(index >= preorder.size() || startInd>endInd)
            return NULL;
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        int pos = mp[element];
        root->left = solve(preorder, index, startInd, pos-1);
        root->right = solve(preorder, index, pos+1, endInd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // create inorder mapping
        int n = inorder.size();
        for(int i=0; i<n; i++)
            mp[inorder[i]] = i;
        
        int index = 0;
        return solve(preorder, index, 0, n-1);
    }
};