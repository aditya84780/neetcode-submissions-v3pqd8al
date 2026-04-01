class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> prefix;
        prefix.resize(n);
        prefix[0] = nums[0];
        for(int i = 1; i< n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int max_num = -1e9, min_num = 1e9;
        int max_num_index = 0, min_num_index = 0;
        int ans = -1e9;
        for(int i = 0; i<n; i++) {
            if(prefix[i] > max_num) {
                max_num = prefix[i];
                max_num_index = i;
            }
            if(prefix[i] < min_num) {
                min_num = prefix[i];
                min_num_index = i;
            }
            ans = max(ans, nums[i]);
            if(max_num_index > min_num_index) {
                ans = max(ans, max_num - min_num);
            }
            ans = max(ans, prefix[i]);
        }
        return ans;
    }
};
