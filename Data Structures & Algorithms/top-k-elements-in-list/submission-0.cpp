class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> sorted_freq;
        for(int num : nums) {
            freq[num]++;
        }
        for(auto entry: freq) {
            sorted_freq.push({entry.second, entry.first});
        }
        vector<int> ans;
        while(k--) {
            ans.push_back(sorted_freq.top().second);
            sorted_freq.pop();
        }
        return ans;
    }
};
