class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int m = INT_MIN;
        stack<pair<int,int>> st;
        for (int i = 0; i < heights.size(); i++) {
            int idx = i;
            while (!st.empty() && heights[i] < st.top().second) {
                pair<int,int> highBar = st.top();
                st.pop();
                int width = i - highBar.first;
                int height = highBar.second;
                m = max(m, width*height);
                idx = highBar.first;
            }

            if (st.empty() || heights[i] > st.top().second) {
                st.push({idx, heights[i]});
            }
        }

        while (!st.empty()) {
            pair<int,int> highBar = st.top();
            cout << highBar.first << " " << highBar.second << endl;
            st.pop();
            int width = heights.size() - highBar.first;
            int height = highBar.second;
            m = max(m, width*height);
        }

        return m;
    }
};
