class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        
        for (auto i : s){
            if (i=='(' || i=='[' || i=='{'){
                char_stack.push(i);
            }
            else if (!char_stack.empty() 
                && ((i == ')' && char_stack.top()=='(') 
                || (i == ']' && char_stack.top()=='[')
                || (i == '}' && char_stack.top()=='{'))){
                char_stack.pop();
            }
            else{
                return false;
            }
        }
        if (char_stack.empty()){
            return true;
        }
        return false;
    }
};