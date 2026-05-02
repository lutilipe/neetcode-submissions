class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int maxLeft = 0;
        int maxRight = 0;

        int total = 0;

        while (r > l) {
            if (height[l] < height[r]) {
                if (height[l] >= maxLeft) {
                    maxLeft = height[l];
                } else {
                    total += maxLeft - height[l];
                }
                l++;
            } else {
                if (height[r] >= maxRight) {
                    maxRight = height[r];
                } else {
                    total+=maxRight - height[r];
                }
                r--;
            }
        }

        return total;
    }
};

/* 

l = 0;
r = l + 1;

areaTotal = 0;

enquanto r < size(alturas)
    se h[r] > h[l]:
        l = r;
        r++;
    senao:
        curr = 0;
        enquanto r < size(h) && h[l] > h[r]:
            diff = h[l] - h[r];
            r++;
            curr+=diff;
        se r < size(h):
            areaTotal += curr;
            l = r;
            r++;
*/