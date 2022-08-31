class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
        int totSum=0;
        
        for(int i: cards) totSum += i;
        if(n==k) return totSum;
        
        int s = 0, e = n-k-1;
        int winSum = 0;
        for(int i=s; i<=e; i++) winSum += cards[i];
        
        int minWinSum = winSum;
        while(e<n-1){
            winSum -= cards[s];
            s++;
            e++;
            winSum += cards[e];
            minWinSum = min(minWinSum, winSum);
        }
        return totSum-minWinSum;
    }
};