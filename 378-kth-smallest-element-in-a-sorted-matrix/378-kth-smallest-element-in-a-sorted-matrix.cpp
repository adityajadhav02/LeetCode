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

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<node*, vector<node*>, compare> minHeap;
        
        int n = matrix.size();
        for(int i = 0; i<n; i++)
            minHeap.push(new node(matrix[i][0], i, 0));
        
        int ans = 0;
        for(int i = 1; i<=k; i++){
            node* curr = minHeap.top();
            minHeap.pop();
            
            ans = curr->data;
            int currRow = curr->row;
            int currCol = curr->col;
            
            if(currCol + 1 < n){
                minHeap.push(new node(matrix[currRow][currCol+1], currRow, currCol+1));
            }
        }
        return ans;
    }
};