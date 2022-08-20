class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int st = i+1, end = n-1;
            while(st < end){                
                int currSum = nums[st] + nums[end] + nums[i];
                
                if(currSum == target) return currSum;
                if(abs(currSum-target) < diff){
                    diff = abs(currSum-target);
                    ans = currSum;
                }
                
                if(currSum > target)
                    end--;
                    
                else if(currSum < target)
                    st++;
            }
        }
         return ans;   
    }
};