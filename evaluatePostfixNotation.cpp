class Solution {
    
    int evaluate(int a, int b, string op){
        if(op == "+")
            return a + b;
        
        if(op == "-")
            return a - b;
        
        if(op == "/")
            return a / b;
        
        if(op == "*")
            return a * b;
        
    
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        
        if(tokens.size() == 1)
            return stoi(tokens[0]);
        
        int ans = 0;
        
        stack<string>st;
                
        for(string token : tokens){
            
            if(token != "+" && token != "/" && token != "*" && token != "-"){
                st.push(token);
            }
            else{
                int operand2 = stoi(st.top());
                st.pop();
                int operand1 = stoi(st.top());
                st.pop();
                
                ans = evaluate(operand1, operand2, token);
                
                st.push(to_string(ans));
            }
        }
        
        return ans;
        
    }
};
