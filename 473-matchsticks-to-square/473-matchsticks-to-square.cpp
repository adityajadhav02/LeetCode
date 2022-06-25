class Solution {
public:
    bool solve(vector<int> &sides, vector<int> &nums, int index, int sideLen){
        
        if(index == nums.size())
        return (sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]);
        
        for(int i=0; i<4; i++){
            if(sides[i] + nums[index] > sideLen)
                continue;
            
            sides[i] += nums[index];
            if(solve(sides, nums, index+1, sideLen))
                return true;
            
            sides[i] -= nums[index];
            
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sides(4, 0);
        
        int sum = 0;
        for(int i: nums)
            sum += i;
        
        if(sum%4 != 0)
            return false;
        
        return solve(sides, nums, 0, sum/4);
    }
};