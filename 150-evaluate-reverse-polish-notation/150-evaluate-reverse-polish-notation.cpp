class Solution {
public:
    int getAns(int a, int b, string i){
        if(i=="+") return a+b;
        if(i=="-") return a-b;
        if(i=="*") return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);
        stack<string> s;
        int curr = 0;
        for(auto i: tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/") s.push(i);
            else{
                int b = stoi(s.top());
                s.pop();
                int a = stoi(s.top());
                s.pop();
                
                curr = getAns(a, b, i);
                s.push(to_string(curr));
            }
        }
        // if(s.empty()) return curr;
        // return curr + stoi(s.top());
        return curr;
    }
};