class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            if(adj[u].size() > 1)
                return u;
            
            else if(adj[v].size() > 1)
                return v;
        }
        
        return -1;
    }
};