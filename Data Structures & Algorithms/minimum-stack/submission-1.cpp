class MinStack {
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            minStack.push(val);
        } else {
            int minElement = minStack.top();
            if (val < minElement) {
                minStack.push(val);
            } else {
                minStack.push(minElement);
            }
        }
        st.push(val);
    }
    
    void pop() {
        minStack.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
