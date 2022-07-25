class Solution {
public:
    int binSearch(vector<int> &nums, int target, bool isFirst){
        int s=0, e=nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] > target)
                e = mid-1;

            else if(nums[mid] < target)
                s = mid+1;
            
            else{
                ans = mid;
                if(isFirst)
                    e = mid-1;
                else
                    s = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        
        ans[0] = binSearch(nums, target, true);
        
        if(ans[0] != -1)
        ans[1] = binSearch(nums, target, false);
        
        return ans;
    }
};