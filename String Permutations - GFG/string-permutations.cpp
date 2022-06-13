// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    vector<string> ans;
    //Complete this function
    
    void solve(int index, string &s){
        // base case
        if(index == s.size()){
            ans.push_back(s);
            return;
        }
        
        for(int i=index; i<s.size(); i++){
            swap(s[i], s[index]);
            solve(index+1, s);
            swap(s[i], s[index]);
        }
    }
    
    vector<string> permutation(string s)
    {
        solve(0, s);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}  // } Driver Code Ends