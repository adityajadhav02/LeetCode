class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> mp;
        
        for(char c: s){
            mp[c]++;
        }
        
        int num = mp[s[0]];
        for(auto i: mp){
            if(num != i.second)
                return false;
        }
        return true;
    }
};