class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> st;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int top = st.top();
                st.pop();
                ans[top] = i - top;
            }
            st.push(i);
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            ans[top] = 0;
        }     

        return ans; 
    }
};
//[30,38,30,36,35,40,28]
//[1, 4, 1, 2, 1, 0, 0]

// 30 (0) 38 (1)
// 38 > 30 ? s -> ans[0] = 1-0. st.push(38(1))
// 30 > 38 ? n -> st.push(30(2))
// 36 > 30 ? s -> ans[2] = 3-2
// 36 > 38 ? n -> st.push(36(3))
// 35 > 36 ? n -> st.push(35(4))
// 40 > 35 ? s -> ans[4] = 5 -4
// 40 > 36 ? s -> ans[3] = 5 - 3
// 40 > 38 ? s -> ans[1] = 5 - 1


/* 
 while (!q)
*/