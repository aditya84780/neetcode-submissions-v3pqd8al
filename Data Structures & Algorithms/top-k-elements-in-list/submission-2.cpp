class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> flist(nums.size()+1);
        for(int num : nums) {
            freq[num]++;
        }
        for(auto entry: freq) {
            flist[entry.second].push_back(entry.first);
        }
        // sort(flist.begin(), flist.end());
        int count = 0;
        vector<int> ans;
        for(int i = flist.size()-1; i>0; i--) {
            for(int n: flist[i]) {
                ans.push_back(n);
                if(ans.size() == k) return ans;
            }
        }
    }
};
