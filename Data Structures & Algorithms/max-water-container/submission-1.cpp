class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l =0;
        int r = heights.size() - 1;
        int maxArea = 0;
        while (r > l) {
            int area = min(heights[l], heights[r]) * (r-l);
            maxArea = max(maxArea, area);

            if (heights[l] > heights[r]) r--;
            else l++;
        }
        return maxArea;
    }
};
