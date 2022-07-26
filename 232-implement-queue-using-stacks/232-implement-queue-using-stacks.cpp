class MyQueue {
private:
    stack<int> stack_;
    stack<int> que_;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack_.push(x);
    }
    
    int pop() {
        int result;
        if (que_.empty()){
            while(!stack_.empty()){
                que_.push(stack_.top());
                stack_.pop();
            }
        }
        result = que_.top();
        que_.pop();
        return result;
    }
    
    int peek() {
        if(que_.empty()){
            while(!stack_.empty()){
                que_.push(stack_.top());
                stack_.pop();
            }
        }
        return que_.top();
    }
    
    bool empty() {
        if(!stack_.empty()){return false;}
        return que_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */