class Solution {
public:
    // min Insertions = n - longest palindromic subsequence.
    
    int optimal(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    // base case
    // shift to right ,, ind = ind+1
    for(int j=0; j<=m; j++) prev[j] = 0;
    
    for(int ind1=1; ind1<=n; ind1++){
        for(int ind2=1; ind2<=m; ind2++){
            // match
            if(s[ind1-1] == t[ind2-1]) 
                curr[ind2] = 1+prev[ind2-1];

            // not match
            else
            curr[ind2] = max(prev[ind2], curr[ind2-1]);
        }
        prev = curr;
    }
    return curr[m];
}
    
    int minInsertions(string str) {
        string rev = str;
        reverse(rev.begin(), rev.end());
        
        int LPS = optimal(str, rev);
        return str.size()-LPS;
    }
};