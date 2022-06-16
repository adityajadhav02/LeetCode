// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool isCyclicDFS(int node, int parent, vector<bool> &visited, vector<int> adj[]){
        visited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool isCyclic = isCyclicDFS(neighbour, node, visited, adj);
                if(isCyclic)
                return true;
            }
            
            else if(neighbour != parent)
            return true;
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<bool> visited(v);
        
        for(int i = 0; i<v; i++){
            if(!visited[i]){
                bool check = isCyclicDFS(i, -1, visited, adj);
                if(check)
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends