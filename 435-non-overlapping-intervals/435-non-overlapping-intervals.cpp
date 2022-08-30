class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // sort endpoints ascending
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 0;
        auto prev = intervals[0];
        for(auto i: intervals){
            if(prev[1] > i[0]) cnt++;
            else
                prev = i;
        }
        return cnt-1;
    }
};