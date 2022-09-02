class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int zeroCnt = 0, ans = 0;
        
        for(int end = 0; end<nums.size(); end++){
            if(nums[end]==0) zeroCnt++;
            while(zeroCnt > k ){
                if(nums[start] == 0) zeroCnt--;
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};