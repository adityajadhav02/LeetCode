class Solution {
public:
    bool checkInclusion(string p, string s) {
        int sLen = s.size();
        int pLen = p.size();
        
        if(sLen < pLen) return false;
        
        vector<int> ans;
        vector<int> sFreq(26, 0);
        vector<int> pFreq(26, 0);
        
        for(int i=0; i<pLen; i++){
            sFreq[s[i]-'a']++;
            pFreq[p[i]-'a']++;
        } 
        
        if(pFreq == sFreq) return true;
        
        for(int i=pLen; i<sLen; i++){
            // Slide the window and change freq
            sFreq[s[i - pLen]-'a']--;
            sFreq[s[i]-'a']++;
            
            if(sFreq == pFreq) return true;
        }
        return false;
    }
};