class Solution {
public:
int n;
    int longestConsecutive(vector<int>& nums) {
        n = nums.size();    
        unordered_map<int,int> mp, sum;
        int ans = 0;
        for(auto num: nums) {
            if(mp[num])continue;
            int len = mp[num+1] + mp[num-1] + 1;
            mp[num] = len;
            mp[num + mp[num+1]] = len;
            mp[num - mp[num-1]] = len;
            ans = max(ans, len);
        }
        return ans;
    }
};
