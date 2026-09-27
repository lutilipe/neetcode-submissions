class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<pair<int,int>> st;
       vector<int> ans(temperatures.size());

       for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                pair<int,int> t = st.top();
                st.pop();
                ans[t.second] = i - t.second;
            }

            st.push({temperatures[i], i});
       }

       return ans; 
    }
};


// [30,38,30,36,35,40,28]

// [0, 4, 1, 2, 1]
// stack = [ <40, 5>, <28, 6>]
// while (!st.empty()) arr[top.second] = 0;