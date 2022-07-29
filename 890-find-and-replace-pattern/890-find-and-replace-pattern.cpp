class Solution {
public:
    string normalise(string pattern){
        unordered_map<char, char> mp;
        char ch = 'a';
        
        for(auto c : pattern){
            if(mp.count(c) == 0) mp[c] = ch++;
        }
        
        for(auto &ch: pattern) ch = mp[ch];
        
        return pattern;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p = normalise(pattern);
        vector<string> ans;
        for(auto i: words)
            if(normalise(i) == p) ans.push_back(i);
        
        return ans;
    }
};