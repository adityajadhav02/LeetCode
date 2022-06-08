class Solution {
public:
    bool isPal(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        
        if(isPal(s))
            return 1;
        
//         int a = 0, b=0;
//         for(char c: s){
//             if(c=='a')
//                 a++;
//             else
//                 b++;
//         }
        
//         return (a+b);
        return 2;
    }
};