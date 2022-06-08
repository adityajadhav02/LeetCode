// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    
    static bool compare(pair<int, int> &a, pair<int, int> &b){
        if(a.second == b.second)
        return a.first<b.first;
        
        return a.second > b.second;
    }
    
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        // initialise vector by map
        vector<pair<int, int>> v(mp.begin(), mp.end());
        
        sort(v.begin(), v.end(), compare);
        
        vector<int> ans; 
        
        for(auto i: v){
            while(i.second--)
            ans.push_back(i.first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends