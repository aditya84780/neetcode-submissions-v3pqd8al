class Solution {
public:
int n;
vector<int> num_arr;
int dp[1010][2];
    int maxProduct(vector<int>& nums) {
        int res = -1e9;
        int curMin = 1, curMax = 1;
        for(auto num: nums) {
            int tempMin = curMin;
            curMin = min(min(curMax * num, curMin * num), num);
            curMax = max(max(tempMin*num, curMax*num), num);
            res = max(res, curMax);
        }
        return res;
    }
};
