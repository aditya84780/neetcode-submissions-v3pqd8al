class Solution {
public:
int n;
vector<int> num_arr;
int dp[1010][2];
    int maxProduct(vector<int>& nums) {
        num_arr = nums;
        n = nums.size();
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for(int i = 1; i<n; i++) {
            if(nums[i]<0) {
                dp[i][0] = min(nums[i], nums[i]*dp[i-1][1]);
                dp[i][1] = max(nums[i], nums[i]*dp[i-1][0]);
            } else {
                dp[i][0] = min(nums[i], nums[i]*dp[i-1][0]);
                dp[i][1] = max(nums[i], nums[i]*dp[i-1][1]);
            }
        }
        int max_val = -1e9;
        for(int i = 0; i<n; i++) {
            max_val = max(max_val, dp[i][1]);
        }
        return max_val;
    }
};
