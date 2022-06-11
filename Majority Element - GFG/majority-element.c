// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    int cnt = 1;
    int ind = 0;
    
    for(int i=1; i<size; i++){
        if(a[i] == a[ind])
        cnt++;
        
        else cnt--;
        
        if(cnt ==0){
            ind = i;
            cnt = 1;
        }
    }
    
    // confirm
    int element = a[ind];
    int c = 0;
    for(int i=0; i<size; i++){
        if(a[i] == element){
            c++;
            if(c > size/2){
                return element;
            }
        }
    }
    
    return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends