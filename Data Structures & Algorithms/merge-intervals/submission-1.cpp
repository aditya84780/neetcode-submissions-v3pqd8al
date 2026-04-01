class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>> q;
        for(auto it: intervals) {
            q.push({-1*it[0], -1*it[1]});
        }
        vector<vector<int>> ans;
        while(!q.empty()) {
            pair<int, int> f_in = q.top();
            q.pop();
            if(!q.empty()) {
                pair<int, int> s_in = q.top();
                if(-1*f_in.second >= -1*s_in.first) {
                    q.pop();
                    q.push({max(f_in.first, s_in.first), min(s_in.second, f_in.second)});
                } else {
                    vector<int> temp = {-1*f_in.first, -1*f_in.second};
                    ans.push_back(temp);
                }
            } else {
                    vector<int> temp = {-1*f_in.first, -1*f_in.second};
                    ans.push_back(temp);
                } 
        }
        return ans;
    }
};
