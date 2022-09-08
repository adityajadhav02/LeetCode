class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        for(int i=0; i<n-1; i++){
            int ele = s[i]-'0';
            int maxi = ele, maxInd = i;
            for(int j=i+1; j<n; j++){
                int a = s[j]-'0';
                if(a>=maxi){
                    maxi = a;
                    maxInd = j;
                }
            }
            if(maxi > ele){
                swap(s[maxInd], s[i]);
                break;
            }
        }
        
        return stoi(s);
    }
};