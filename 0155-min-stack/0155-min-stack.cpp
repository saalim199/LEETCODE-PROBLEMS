class MinStack {
public:
stack<pair<int,int>> s;
int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mini=min(mini,val);
        s.push({val,mini});
    }
    
    void pop() {
        s.pop();
        if(!s.empty()) mini=s.top().second;
        else mini=INT_MAX;
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
       return s.top().second;
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