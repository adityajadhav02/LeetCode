class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start = 1, end = nums.size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            // count elements less than mid in nums
            int cnt = 0;
            for(int i: nums)
                if(i <= mid) cnt++;
            
            if(cnt <= mid)
                start = mid+1;
            
            else 
                end = mid-1;
        }
        return start;
    }
};