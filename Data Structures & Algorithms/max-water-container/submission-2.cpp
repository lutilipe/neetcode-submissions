class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int m = 0;

        while (r > l) {
            int dist = r - l;
            int h = min(heights[r], heights[l]);
            m = max(m, h*dist);

            if (heights[l] > heights[r]) r--;
            else l++;
        }

        return m;
    }
};
