class Solution {
public:
    int countPoints(string rings) {
        bool r[10] = {false};
        bool g[10] = {false};
        bool b[10] = {false};
        int rod;
        
        for(int i = 0; i<rings.size() - 1; i += 2){
            rod = rings[i+1] - '0';
            
            if(rings[i] == 'R')
                r[rod] = true;
            
            if(rings[i] == 'G')
                g[rod] = true;
            
            if(rings[i] == 'B')
                b[rod] = true;
        }
        
        int count = 0;
        for(int i = 0; i<10; i++){
            if(r[i] && g[i] && b[i])
                count++;
        }
        return count;
    }
};