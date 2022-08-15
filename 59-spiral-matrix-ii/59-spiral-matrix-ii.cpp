class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 0));
        
        int rowSt = 0, rowEnd=n-1, colSt=0, colEnd=n-1;
        int count = 0, num=1;
        
        while(count < n*n){
            // fill top row
            for(int i=colSt; i<=colEnd; i++){
                ans[rowSt][i] = num;
                num++;
                count++;
            }
            rowSt++;
            
            // fill last col
            for(int i=rowSt; i<=rowEnd; i++){
                ans[i][colEnd] = num;
                num++;
                count++;
            }
            colEnd--;
            
            // fill last row
            for(int i=colEnd; i>=colSt; i--){
                ans[rowEnd][i] = num;
                num++;
                count++;
            }
            rowEnd--;
            
            // fill first col
            for(int i=rowEnd; i>=rowSt; i--){
                ans[i][colSt] = num;
                num++;
                count++;
            }
            colSt++;
        }
        return ans;
    }
};