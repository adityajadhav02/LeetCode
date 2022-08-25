class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        vector<vector<bool>> isConnected(n, vector<bool>(n, false));
        for(auto i: roads){
            deg[i[0]]++;
            deg[i[1]]++;
            
            isConnected[i[0]][i[1]] = true;
            isConnected[i[1]][i[0]] = true;
        }
        int ans= 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, deg[i]+deg[j]-(isConnected[i][j]==true ? 1 : 0));
            }
        }
        return ans;
    }
};