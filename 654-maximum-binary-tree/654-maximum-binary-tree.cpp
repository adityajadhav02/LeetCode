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
    TreeNode* createTree(vector<int> &nums, int l, int r){
        if(l>r) return NULL;
        
        
        int maxInd = l;
        for(int i = l; i<=r; i++){
            if(nums[i] > nums[maxInd]) maxInd = i; 
        }
        
        TreeNode* root = new TreeNode(nums[maxInd]);
        root->left = createTree(nums, l, maxInd-1);
        root->right = createTree(nums, maxInd+1, r);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        
        return createTree(nums, 0, n-1);
    }
};