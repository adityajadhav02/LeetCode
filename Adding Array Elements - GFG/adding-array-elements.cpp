// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i<n; i++)
        minHeap.push(arr[i]);
        
        int ans = 0;
        
        while(minHeap.top()<k){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            
            minHeap.push(a+b);
            ans++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends