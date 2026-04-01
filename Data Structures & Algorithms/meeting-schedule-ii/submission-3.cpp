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
        int count = 1;
        int n = intervals.size();
        if(n == 1) return 1;
        if(n == 0) return 0;
        int maxa = 0;
        vector<int> prefix(1000010, 0);
        for(auto v: intervals) {
            prefix[v.start]++;
            prefix[v.end]--;
            maxa = max(maxa, v.end);
        }
        int ans = 1;
        for(int i = 0; i<=maxa; i++) {
            prefix[i+1] += prefix[i];
            ans = max(ans, prefix[i+1]);
        }
        return ans;
    }
};
