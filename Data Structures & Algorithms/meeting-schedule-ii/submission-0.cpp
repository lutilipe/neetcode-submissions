/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            if (a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); i++) {
            Interval interval = intervals[i];
            int prevEnd = pq.top();
            if (interval.start >= prevEnd) {
                pq.pop();
            }

            pq.push(interval.end);
        }

        return pq.size();
    }
};
