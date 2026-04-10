class MinStack {
public:
    stack<int>main;
    stack<int>minst;
    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);
        if(minst.empty() || val<=minst.top())
        {
            minst.push(val);
        }
    }
    
    void pop() {
        if(main.top()==minst.top())
        {
            minst.pop();
        }
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minst.top();
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