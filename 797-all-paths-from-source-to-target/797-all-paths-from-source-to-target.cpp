class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node, int n, vector<int> &path, vector<vector<int>>& graph){
        
        path.push_back(node);
        
        if(node == n-1){
            ans.push_back(path);
        }
        
        for(auto nbr : graph[node]){
            dfs(nbr, n, path, graph);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> path;
        dfs(0, n, path, graph);
        return ans;
    }
};