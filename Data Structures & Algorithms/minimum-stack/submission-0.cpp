class MinStack {
public:
    stack<int> st;
    vector<int> prefix;

    MinStack() {
        
    }
    
    void push(int val) {
        if (!prefix.size()) {
            prefix.push_back(val);
        } else {
            int lastMin = prefix[prefix.size() - 1];
            if (val > lastMin) {
                prefix.push_back(lastMin);
            } else {
                prefix.push_back(val);
            }
        }

        st.push(val);
    }
    
    void pop() {
        st.pop();
        prefix.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return prefix[prefix.size() - 1];
    }
};

// getMin
// guardar ref para menor valor

// top | min = *(int)0
// [0, 2, 0]
// [2, 0]

// 0 2 1 
// 2 1