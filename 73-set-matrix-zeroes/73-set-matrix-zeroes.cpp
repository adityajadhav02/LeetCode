class Solution {
public:
    int found(vector<int> a, int target){
        for(int i: a)
            if(i == target) return true;
        
        return false;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row, col;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(found(row, i) || found(col, j))
                    matrix[i][j] = 0;
            }
        }
    }
};