class Solution {
public:
    bool isValid(string s) {
        stack<char> storage;
        
        for (auto c : s){
            if ((c == '(') || (c == '{') || (c == '[')){
                storage.push(c);
            } else if ((c == ')') || (c== '}') || (c == ']')){
                if (storage.empty()){return false;}
                
                char top = storage.top();
                storage.pop();
                
                if (top == '(' && c == ')'){continue;} 
                if (top == '{' && c == '}'){continue;}
                if (top == '[' && c == ']'){continue;}
                return false;
            }
        }
        
        if (storage.empty()){
            return true;
        }
        return false;
    }
};