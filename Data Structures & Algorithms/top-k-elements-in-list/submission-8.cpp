class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<pair<int,int>> rev_freq;
        vector<int> ans;
        if(k ==0) return ans;
        if(nums.size() == 0) return ans;
        for(auto v: nums) {
            freq[v]++;
        }
        for(auto mp: freq) {
            rev_freq.push_back(make_pair(mp.second, mp.first));
        }
        sort(rev_freq.begin(), rev_freq.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.first != b.first ? a.first > b.first : a.second < b.second;
});
        // reverse(rev_freq.begin(), rev_freq.end());
        for(int i = 0; i<k; i++) {
            ans.push_back(rev_freq[i].second);
        }
        return ans;
    }
};
