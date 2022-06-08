class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int i=0, j;
        int maxi = 0;
        while(i<n){
            int j = i;
            int curr = 0;
            mp.clear();
            while(j<n){
                if(mp.find(s[j]) == mp.end()){
                    mp[s[j]] = j;
                    curr = mp.size();
                    maxi = max(curr, maxi);
                }
                else{
                    
                    break;
                }
                j++;
            }
            i++;
        }
        return maxi;
    }
};