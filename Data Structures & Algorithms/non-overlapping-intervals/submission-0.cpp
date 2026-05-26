class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        int prevEnd = intervals[0][1];
        int removed = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                prevEnd = min(prevEnd, intervals[i][1]);
                removed++;
            } else {
                prevEnd = intervals[i][1];
            }
        }

        return removed;
    }
};
