class MinStack {
public:
    vector<pair<long,long>>st;
    long min=INT_MAX;
    MinStack() {
    
    }
    
    void push(int val) {
        

        min=getMin();
        if(val<min)
        {
            min=val;
        }
        st.push_back({val,min});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        if(st.empty())
        return INT_MAX;
        auto x=st.back();
        long mn=x.second;
        return mn;
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