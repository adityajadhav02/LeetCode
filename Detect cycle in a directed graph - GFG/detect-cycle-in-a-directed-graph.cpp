// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool isCyclicDFS(int node, vector<int>adj[], vector<bool> &visited, vector<bool> &dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool isCyclic = isCyclicDFS(neighbour, adj, visited, dfsVisited);
                if(isCyclic)
                return true;
            }
            
            else if(dfsVisited[neighbour])
            return true;
        }
        dfsVisited[node] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        vector<bool> visited(v);
        vector<bool> dfsVisited(v);
        
        for(int i=0; i<v; i++){
            if(!visited[i]){
                bool check = isCyclicDFS(i, adj, visited, dfsVisited);
                if(check)
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends