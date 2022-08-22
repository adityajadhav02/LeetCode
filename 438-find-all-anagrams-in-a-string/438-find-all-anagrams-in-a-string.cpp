class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        
        if(sLen < pLen) return {};
        
        vector<int> ans;
        vector<int> sFreq(26, 0);
        vector<int> pFreq(26, 0);
        
        for(int i=0; i<pLen; i++){
            sFreq[s[i]-'a']++;
            pFreq[p[i]-'a']++;
        } 
        
        if(pFreq == sFreq) ans.push_back(0);
        
        for(int i=pLen; i<sLen; i++){
            // Slide the window and change freq
            sFreq[s[i - pLen]-'a']--;
            sFreq[s[i]-'a']++;
            
            if(sFreq == pFreq) ans.push_back(i-pLen+1);
        }
        return ans;
    }
};