class Solution {
    
struct comp{
    bool operator()(string &a, string &b){
        return a+b > b+a;
    }
}comp1;
    
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i: nums)
            v.push_back(to_string(i));
        
        string ans = "";
        sort(v.begin(), v.end(), comp1);
        for(auto i: v) ans += i;
        if(ans[0] == '0') return "0";
        // while(ans[0]==0 && ans.size()>0) ans.erase(0, 1);
        return ans;
    }
};