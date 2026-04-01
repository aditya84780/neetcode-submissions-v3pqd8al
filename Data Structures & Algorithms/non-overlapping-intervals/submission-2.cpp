class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // int tail = 0;
        int head = 1;
        int n = intervals.size();
        if(n == 1) return 0;
        sort(intervals.begin(), intervals.end());
        int minEnd = intervals[0][1];
        int count = 0;
        while(head < n) {
            if(intervals[head][0] < minEnd) {
                count++;
                minEnd = min(intervals[head][1], minEnd);
            } else {
                minEnd = intervals[head][1];
            }
            head++;
            // tail++;
        }
        return count;
    }
};
