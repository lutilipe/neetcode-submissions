class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int l = 0;
        int r = heights.size() - 1;
        while (r > l) {
            int h = min(heights[r], heights[l]);
            int w = r - l;
            area = max(area, h*w);
            if (heights[r] > heights[l]) l++;
            else r--;
        }
        return area;
    }
};

//[L,7,2,5,4,7,3,R]
//[1,7,2,5,4,7,3,6]

// h = 1 w = 7 a = 7 ma = 7
