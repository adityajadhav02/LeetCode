class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        
        int minInd = 0, maxInd = 0;
        int mini = nums[0], maxi = nums[0];
        
        for(int i=1; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxInd = i;
            }
            else if(nums[i] < mini){
                mini = nums[i];
                minInd = i;
            }
        }
        
        int left = min(minInd, maxInd);
        int right = max(minInd, maxInd);
        
        int delLeft = left+1;
        int delRight = n - right;
        int gap = right-left;
        
        int ans = min(delLeft+delRight, min(delLeft+gap, delRight+gap));
        return ans;
    }
};