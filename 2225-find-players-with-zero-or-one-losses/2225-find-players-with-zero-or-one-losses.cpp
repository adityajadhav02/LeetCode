class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> players;
        map<int, int> loses;
        
        for(auto i : matches){
            int w = i[0];
            int l = i[1];
            players.insert(w);
            players.insert(l);
            loses[l]++;
        }
        vector<int> oneLost, notLost;
        for(auto i: players){
            if(loses[i] == 0)
                notLost.push_back(i);
            else if(loses[i] == 1)
                oneLost.push_back(i);
        }
        
        return {notLost, oneLost};
    }
};