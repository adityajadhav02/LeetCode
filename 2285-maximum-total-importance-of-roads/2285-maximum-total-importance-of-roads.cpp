class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indegree(n, 0);
        
        for(auto i: roads){
            int u = i[0];
            int v = i[1];
            indegree[u]++;
            indegree[v]++;
        }
        sort(indegree.begin(), indegree.end());
        long long ans = 0;
        for(int i=0; i<n; i++)
            ans += indegree[i]*(i+1);
        
        return ans;
    }
};