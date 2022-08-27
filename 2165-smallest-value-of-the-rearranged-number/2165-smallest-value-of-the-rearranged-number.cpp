class Solution {
public:
    long long smallestNumber(long long num) {
        string s = to_string(abs(num));
        sort(s.begin(), s.end());
        
        // sort descending if negative
        if(num < 0){
            reverse(s.begin(), s.end());
            return stoll(s)*(num>0 ? 1 : -1);
        } 
        
        if(s[0]=='0'){
            for(int i=0; i<s.size(); i++){
                if(s[i] != '0'){
                    swap(s[0], s[i]);
                    break;
                }
            }
        }
        return stoll(s);
    }
};