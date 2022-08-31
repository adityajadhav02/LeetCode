class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int m = profit.size();
        vector<pair<int, int>> work;
        for(int i=0; i<m; i++)
            work.push_back(make_pair(profit[i], difficulty[i]));
        
        sort(work.begin(), work.end(), cmp);
        
        int maxProfit = 0;
        sort(worker.begin(), worker.end(), greater<int>());
        int i=0, j=0;
        while(i<n && j<m){
            int curDiff = worker[i];
            int reqDiff = work[j].second;
            int curProfit = work[j].first;
            if(curDiff >= reqDiff){
                maxProfit += curProfit;
                i++;
            }
            else{
                j++;
            }
        }
        return maxProfit;
    }
};