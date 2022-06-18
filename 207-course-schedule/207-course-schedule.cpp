class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj(prerequisites.size());
        
        // make adjacency list
        for(auto i: prerequisites){
            int u = i[1];
            int v = i[0];
            
            adj[u].push_back(v);
        }
        
        // find indegree of all nodes
        vector<int> indegree(numCourses, 0);
        for(auto i: adj){
            for(auto j: i.second)
            indegree[j]++;
        }
        
        // push 0 indegree nodes in q
        queue<int> q;
        for(int i=0; i<indegree.size(); i++)
            if(indegree[i]==0)
                q.push(i);
        
        
        //bfs
        int ans = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans++;
            for(auto neighbour : adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                    q.push(neighbour);
            }
        }
        
        // cycle not present
        if(ans == numCourses)
            return true;
            
        // cycle present
        return false;
    }
};