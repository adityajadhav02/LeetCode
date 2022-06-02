// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range

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
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        priority_queue<node*, vector<node*>, compare> minHeap;
        
        int maxi = INT_MIN, mini = INT_MAX;
        
        // push k nodes in minHeap
        for(int i=0; i<k; i++){
            node* temp = new node(KSortedArray[i][0], i, 0);
            minHeap.push(temp);
            maxi = max(maxi, temp->data);
            mini = min(mini, temp->data);
        }
        
        int start = mini, end = maxi;
        
        while(!minHeap.empty()){
            node* top = minHeap.top();
            minHeap.pop();
            mini = top->data;
            
            // update range
            if(maxi-mini < end-start){
                end = maxi;
                start = mini;
            }
            
            // check if next element exist
            if(top->col +1 < n){
                maxi = max(maxi, KSortedArray[top->row][top->col + 1]);
                minHeap.push(new node(KSortedArray[top->row][top->col + 1], top->row, top->col + 1));
            }
            else
            break;
        }
        pair<int, int> p = make_pair(start, end);
        return p;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends