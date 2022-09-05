/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            int s = q.size();
            for(int i=0; i<s; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp){
                    level.push_back(temp->val);
                    for(auto i: temp->children) q.push(i);
                }
                
            }
            ans.push_back(level);
        }
        return ans;
    }
};