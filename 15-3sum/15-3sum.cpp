class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            int target = -nums[i];
            
            int st = i+1, end = n-1;
            while(st < end){
                int sum = nums[st] + nums[end];
                
                if(sum > target)
                    end--;
                else if(sum < target)
                    st++;
                
                else{
                    vector<int> triplet = {nums[i], nums[st], nums[end]};
                    ans.push_back(triplet);
                    
                    // skip duplicates of st
                    while(st<end && nums[st] == triplet[1]) st++;
                    
                    // skip duplicates of end
                    while(st<end && nums[end] == triplet[2]) end--;
                }
            }
            
            // skip duplicates of i
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
         return ans;   
    }
};