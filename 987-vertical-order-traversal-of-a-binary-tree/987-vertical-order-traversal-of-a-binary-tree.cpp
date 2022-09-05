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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        
        while(!q.empty()){
            vector<pair<int, int>> temp;
            int s = q.size();
            for(int i=0; i<s; i++){
                auto front = q.front();
                q.pop();
                
                int hd = front.first;
                auto node = front.second;
                
                temp.push_back(make_pair(hd, node->val));
                if(node->left) q.push(make_pair(hd-1, node->left));
                if(node->right) q.push(make_pair(hd+1, node->right));
            }
            sort(temp.begin(), temp.end());
            for(auto i: temp)
                mp[i.first].push_back(i.second);
        }
        for(auto i: mp) ans.push_back(i.second);
        return ans;
    }
};