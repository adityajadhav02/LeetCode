class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int city){
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[city][i]==1 && !visited[i]){
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }
        return count;
    }
};