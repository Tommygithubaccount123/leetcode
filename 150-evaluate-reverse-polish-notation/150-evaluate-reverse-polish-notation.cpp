class Solution {
public:
    int evaluate(int a, int b, string op){
        if (op == "+"){return a+b;}
        if (op == "-"){return a-b;}
        if (op == "*"){return a*b;}
        return a/b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> storage;
        
        for (auto token : tokens){
            if (token.size()>1 || isdigit(token[0])){
                storage.push(token);
            } else {
                int second = stoi(storage.top());
                storage.pop();
                int first = stoi(storage.top());
                storage.pop();
                storage.push(to_string(evaluate(first, second, token)));
            }
        }
        
        return stoi(storage.top());
    }
};