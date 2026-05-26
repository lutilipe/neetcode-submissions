class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        vector<int>& curr = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& interval = intervals[i];
            if (interval[0] >= curr[0] && interval[0] <= curr[1]) {
                curr[1] = max(curr[1], interval[1]);
            } else {
                merged.push_back(curr);
                curr = interval;
            }
        }

        merged.push_back(curr);

        return merged;
    }
};
