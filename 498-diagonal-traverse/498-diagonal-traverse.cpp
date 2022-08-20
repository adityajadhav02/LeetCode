class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        vector<int> ans;
        
        int m = a.size();
        int n = a[0].size();
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(a[i][j]);
            }
        }
        
        
        for(int sum = 0; sum <= m+n; sum++){
            vector<int> v = mp[sum];
            // push in reverse
            if(sum%2 == 0){
                for(int j=v.size()-1; j>=0; j--)
                    ans.push_back(v[j]);
            }
            
            // push as it is
            else{
                for(auto k: v)
                    ans.push_back(k);
            }
        }
        return ans;
    }
};