class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> storage;
        vector<string> operators = {"+","-","*","/"};
        for (int i=0; i<n; i++){
            bool ifOperator = false;
            for (auto o : operators){
                if (tokens[i] == o){
                    ifOperator = true;
                    break;
                }
            }
            if (ifOperator==false){
                storage.push(tokens[i]);
            } else {
                int first = stoi(storage.top());
                storage.pop();
                int second = stoi(storage.top());
                storage.pop();
                int evaluate = operatorHelp(second, first, tokens[i]);
                storage.push(to_string(evaluate));
            } 
        }
        
        return stoi(storage.top());
    }
    
    int operatorHelp(int a, int b, string c){
        if (c == "+"){return a+b;}
        if (c == "-"){return a-b;}
        if (c == "*"){return a*b;}
        if (c == "/"){return a/b;}
        return -1;
    }
    
};