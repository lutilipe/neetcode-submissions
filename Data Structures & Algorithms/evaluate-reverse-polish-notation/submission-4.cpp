class Solution {
public:
    bool isOperator(string c) {
        return c == "+" || c == "-" || c == "*" || c == "/";
    }

    int evalRPN(vector<string>& tokens) {
       stack<int> st;
       for (string c : tokens) {
            if (!isOperator(c)) st.push(stoi(c));
            else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                int res = 0;

                if (c == "+") res = a+b;
                else if (c == "-") res = b-a;
                else if (c == "*") res = a*b;
                else if (c == "/") res = b/a;

                st.push(res);
            }
       }

       if (st.empty()) return 0;
       return st.top();
    }
};