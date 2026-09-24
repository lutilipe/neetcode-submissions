class MinStack {
    vector<int> m;
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (m.size()) {
            m.push_back(min(m.back(), val));
        } else {
            m.push_back(val);
        }
    }
    
    void pop() {
        st.pop();
        m.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if (m.size()) return m.back();
        return -1;
    }
};
