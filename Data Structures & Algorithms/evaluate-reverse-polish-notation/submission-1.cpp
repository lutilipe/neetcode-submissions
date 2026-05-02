class Solution {
public:
    bool isOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (!isOperator(token)) {
                st.push(stoi(token));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                int res;

                if (token == "+") res=a+b;
                else if (token == "-") res=a-b;
                else if (token == "*") res=a*b;
                else  res=a/b;
                
                st.push(res);
            }
        }

        return st.top();
    }
};
