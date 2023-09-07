class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        
        for (auto token : tokens){
            if (token.size() > 1 || isdigit(token[0])){
                nums.push(stoi(token));
            }else{
                int x = nums.top();
                nums.pop();
                int y = nums.top();
                nums.pop();
                int result;
                
                if (token == "+"){
                    result = x + y;
                } else if (token == "-"){
                    result = y - x;
                } else if (token == "*"){
                    result = x * y;
                } else if (token == "/"){
                    result = y / x;
                }
                nums.push(result);
            }
        }
        return nums.top();    
    }
};