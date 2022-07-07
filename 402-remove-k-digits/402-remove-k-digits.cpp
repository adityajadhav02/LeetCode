class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>= num.size())
            return "0";
        if(k==0)
            return num;
        
        stack<char> st;
        
        st.push(num[0]);
        
        for(int i=1; i<num.size(); i++){
            while(!st.empty() && k>0 && num[i]<st.top()){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
            
            if(st.size()==1 & st.top()=='0')
                st.pop();
        }
        
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        if(ans.length() == 0)
            return "0";
        
        return ans;
    }
};