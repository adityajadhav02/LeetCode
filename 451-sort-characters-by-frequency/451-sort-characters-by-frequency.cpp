class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        
        for(auto c: s) mp[c]++;
        
        vector<string> bucket(s.size()+1, "");
        string ans;
        for(auto i : mp){
            int n = i.second;
            char c = i.first;
            bucket[n].append(n, c);
        }
        
        for(int i=s.size(); i>0; i--){
            if(!bucket[i].empty()){
                ans.append(bucket[i]);
            }
        }
        return ans;
    }
};