// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        int * ans = new int[2]{-1};
        int val=0, element = 0;
        
        for(int i=0; i<n; i++){
            val = abs(a[i]);
            element = a[val - 1];
            
            if(element > 0)
            a[val - 1] = -1 * element;
            
            else
            ans[0] = val;
        }
        
        for(int i=0; i<n; i++){
            if(a[i] > 0){
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends