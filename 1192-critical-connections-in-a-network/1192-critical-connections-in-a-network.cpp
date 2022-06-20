class Solution {
public:
    
    void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &vis, int &parent, int &timer, vector<vector<int>> &ans){
        vis[node] = true;
        disc[node] = low[node] = timer++;
        
        for(auto neighbour : adj[node]){
            if(neighbour == parent)
                continue;
            
            if(!vis[neighbour]){
                dfs(neighbour, adj, disc, low, vis, node, timer, ans);
                
                // update low for node
                low[node] = min(low[node], low[neighbour]);
                
                // check if edge is a bridge
                if(low[neighbour] > disc[node]){
                    vector<int> bridge;
                    bridge.push_back(node);
                    bridge.push_back(neighbour);
                    ans.push_back(bridge);
                }
            }
            
            else{
                // back edge
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // create adjacency list
        unordered_map<int, list<int>> adj;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>> ans;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false); 
        int parent = -1;
        int timer = 0;
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                dfs(i, adj, disc, low, vis, parent, timer, ans);
        }
        
        return ans;
    }
};