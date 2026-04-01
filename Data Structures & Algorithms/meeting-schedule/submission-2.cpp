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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> times;
        for(auto it: intervals) {
            times.push_back({it.start, it.end});
        }
        sort(times.begin(), times.end());
        int n = times.size();
        for(int i = 0; i<n-1; i++) {
            if(times[i].second > times[i+1].first) {
                return false;
            }
        }
        return true;
    }
};
