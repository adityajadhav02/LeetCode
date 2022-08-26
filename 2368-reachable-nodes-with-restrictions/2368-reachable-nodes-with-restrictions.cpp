class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        unordered_map<int, list<int>> adj;
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int count = 0;
        queue<int> q;
        q.push(0);
        vis[0] = true;
        set<int> s(rest.begin(), rest.end());
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            if(s.count(front)) continue;
            count++;
            
            for(auto nbr: adj[front]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return count;
    }
};