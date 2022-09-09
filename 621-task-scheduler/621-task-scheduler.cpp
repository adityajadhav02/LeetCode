class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for(char i: tasks){
            mp[i]++;
            maxFreq = max(maxFreq, mp[i]);
        }
        
        int ans = (maxFreq-1)*(n+1);
        
        for(auto i: mp) 
            if(i.second == maxFreq) ans++;
        
        return max(ans, (int)tasks.size());
    }
};