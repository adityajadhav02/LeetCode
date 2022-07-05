class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i: nums)
            s.insert(i);
        
        int maxi = 0;
        
        for(auto &num : s){
            
            // find the element whose prev is not found..
            if(s.count(num-1))
                continue;
            
            int j = 1;
            while(s.count(num+j))
                j++;
            
            maxi = max(maxi, j);
            
        }
        return maxi;
    }
};