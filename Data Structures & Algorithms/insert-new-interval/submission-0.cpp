class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            vector<int> v = intervals[i];
            if(v[1] < newInterval[0]) {
                ans.push_back(v);
            } else if(v[0] > newInterval[1]) {
                ans.push_back(newInterval);
                for(int j = i; j<n; j++) {
                    ans.push_back(intervals[j]);
                }
                return ans;
            } else {
                newInterval = {min(v[0], newInterval[0]), max(v[1], newInterval[1])};
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
