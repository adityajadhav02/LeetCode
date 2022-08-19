class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // swap columns except middle
        for(int j=0; j<n/2; j++){
            for(int i=0; i<n; i++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};