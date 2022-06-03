// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

class node{
    public:
    int data;
    int row;
    int col;
    
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public: 
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    // push first element of each row in minHeap
    for(int i = 0; i<n; i++)
    minHeap.push(new node(mat[i][0], i, 0));
    
    int ans = 0;
    for(int i=1; i<=k; i++){
        node* curr = minHeap.top();
        minHeap.pop();
        
        ans = curr->data;
        int currRow = curr->row;
        int currCol = curr->col;
        
        if(currCol+1 < n){
            minHeap.push(new node(mat[currRow][currCol+1], currRow, currCol+1));
        }
    }
    
    return ans;
}
