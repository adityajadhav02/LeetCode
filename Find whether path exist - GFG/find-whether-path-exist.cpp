// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    bool ans = false;
    
    bool solve(int srow, int scol, vector<vector<bool>> &visited, vector<vector<int>>& grid){
        // base cases
        int n = grid.size();
        if(srow== n|| srow<0 ||scol== n|| scol<0)
        return false;
        
        if(visited[srow][scol])
        return false;
        
        if(grid[srow][scol] == 0)
        return false;
        
        if(grid[srow][scol] == 2)
        return true;
        
        visited[srow][scol] = true;
        
        if(solve(srow+1, scol, visited, grid) || 
           solve(srow-1, scol, visited, grid) ||
           solve(srow, scol+1, visited, grid) ||
           solve(srow, scol-1, visited, grid) )
           
           return true;
           
           return false;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int srow, scol;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                if(grid[i][j] == 1){
                    srow = i;
                    scol = j;
                }
            }
        }
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        return solve(srow, scol, visited, grid);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends