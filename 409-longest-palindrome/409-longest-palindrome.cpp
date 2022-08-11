class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(char c: s)
            mp[c]++;
        
        int ans=0, oddFlag=0;
        for(auto i: mp){
            int c = i.second;
            if(c%2 == 0)
                ans += c;
            
            else{
                oddFlag=1;
                ans += c-1;
            }
        }
        return ans+oddFlag;
    }
};