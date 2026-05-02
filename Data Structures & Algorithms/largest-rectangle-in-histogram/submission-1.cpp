class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int m = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int minHeight = heights[i];
            int w = 1;
            for (int j = i; j < heights.size(); j++) {
                minHeight = min(minHeight, heights[j]);
                m=max(m, minHeight*w);
                w++;
            }
        }
        return m;
    }
};
