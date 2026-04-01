class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> pos;
        vector<int> ans;
        for(int i = 0; i< n; i++) {
            if(pos.count(target-nums[i])) {
                return {pos[target-nums[i]],i};
            }
            pos[nums[i]] = i;
        }
        return {};
    }
};
