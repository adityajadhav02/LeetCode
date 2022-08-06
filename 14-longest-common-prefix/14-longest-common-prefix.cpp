class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string ans = "";
        
        int n = strs.size();
        string st = strs[0];
        string e = strs[n-1];
        
        for(int i=0; i<st.size(); i++){
            if(st[i] == e[i])
                ans += st[i];
            
            else 
                break;
        }
        
        return ans;
    }
};