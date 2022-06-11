// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int binSearch(int arr[], int x, int n, int pos){
    int start = 0, end = n-1;
    int ans = -1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        
        if(arr[mid] == x){
            ans = mid;
            // for first occ.
            if(pos == 0){
                end = mid-1;
            }
            
            else{
                start = mid+1;
            }
        }
        
        else if(arr[mid] < x)
        start = mid+1;
        
        else
        end = mid-1;
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    vector<int> ans(2, -1);
    
    ans[0] = binSearch(arr, x, n, 0);
    ans[1] = binSearch(arr, x, n, 1);
    
    return ans;
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends