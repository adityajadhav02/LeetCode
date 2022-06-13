// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int> &arr, vector<int> &op){
        // base case
        if(ind >= arr.size()){
            ans.push_back(op);
            return;
        }
        
        // include
        op.push_back(arr[ind]);
        solve(ind+1, arr, op);
        op.pop_back();
        
        // exclude
        solve(ind+1, arr, op);
    }
    vector<vector<int>> subsets(vector<int>& arr)
    {
        vector<int> op;
        solve(0, arr, op);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends