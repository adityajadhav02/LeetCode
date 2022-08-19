class Solution {
public:
    vector<string> ans;
    
    void solve(string digits, int ind, string mp[], string op){
        // base case
        if(ind >= digits.size()){
            if(op.size()>0)
            ans.push_back(op);
            return;
        }
        
        int num = digits[ind]-'0';
        string str = mp[num-1];
        
        for(int i=0; i<str.size(); i++){
            op += str[i];
            solve(digits, ind+1, mp, op);
            op.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string mp[10]={"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, 0, mp, "");
        return ans;
    }
};