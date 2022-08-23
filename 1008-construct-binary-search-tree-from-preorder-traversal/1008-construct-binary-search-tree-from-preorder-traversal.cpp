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
    TreeNode* solve(vector<int> & preorder, int min, int max, int &index){
        if(index >= preorder.size())
            return NULL;
        
        if(preorder[index]<min || preorder[index]>max)
            return NULL;
        
        // The element is in given range => create a new node
        TreeNode* root = new TreeNode(preorder[index]);
        
        // Move to next element
        index++;
        
        // Recursive calls
        root->left = solve(preorder, min, root->val, index);
        root->right = solve(preorder, root->val, max, index);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN, max = INT_MAX;
        int index = 0;
        
        return solve(preorder, min, max, index);
    }
};