class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansInd = 0;
        while(i<chars.size()){
            char curr = chars[i];
            int cnt = 0;
            
            while(i<chars.size() && chars[i] == curr){
                i++;
                cnt++;
            }
            
            chars[ansInd++] = curr;
            if(cnt != 1){
                for(auto c: to_string(cnt))
                    chars[ansInd++] = c;
            }
        }
        return ansInd;
    }
};