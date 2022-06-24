class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            if(front == destination)
                return true;
            
            vis[front] = true;
            for(auto nbr: adj[front]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                }   
            }
        }
        return false;
    }
};