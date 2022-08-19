class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string i: strs){
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        
        for(auto i: mp){
            vector<string> v;
            for(auto j: i.second)
                v.push_back(j);
            
            ans.push_back(v);
        }
        return ans;
    }
};