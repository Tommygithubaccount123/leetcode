class MinStack {
public:
    stack<int> storage;
    stack<int> smaller;
    
    MinStack() {
        
    }
    
    void push(int val) {
        storage.push(val);
        if (smaller.empty() || val <= smaller.top()){
            smaller.push(val);
        }
    }
    
    void pop() {
        int top = storage.top();
        storage.pop();
        if (top == smaller.top()){
            smaller.pop();
        }
    }
    
    int top() {
        return storage.top();
    }
    
    int getMin() {
        return smaller.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */