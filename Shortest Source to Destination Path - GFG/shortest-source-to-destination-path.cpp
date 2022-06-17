// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Data{
    public:
    int x; 
    int y; 
    int dist;
    
    Data(int x, int y, int dist){
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

class Solution {
  public:
    bool isSafe(vector<vector<int>> &grid, int x, int y){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1)
        return true;
        
        return false;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0)
        return -1;
        
        int dirX[4]={1,-1,0,0};
        int dirY[4]={0,0,1,-1};
        
        queue<Data> q;
        q.push(Data(0, 0, 0));
        
        A[0][0] = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Data curr = q.front();
                q.pop();
                
                int currX = curr.x;
                int currY = curr.y;
                int dist = curr.dist;
                
                if(currX==X && currY==Y)
                return dist;
                
                for(int i=0; i<4; i++){
                    int newX = currX + dirX[i];
                    int newY = currY + dirY[i];
                    
                    if(isSafe(A, newX, newY)){
                        A[newX][newY] = 0;
                        q.push(Data(newX, newY, dist+1));
                    }
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends