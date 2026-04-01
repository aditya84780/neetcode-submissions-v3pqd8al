class Solution {
public:
    int n;
    vector<int> money;
    vector<vector<int>> dp;
    int rec(int level, int prev) {
        if(level < 0 || level >= n) return 0;
        if(level == n-1) {
            if(prev == 0) return money[n-1];
            return 0;
        }
        if(dp[level][prev] != -1) return dp[level][prev];
        int ans = 0;
        if(prev) ans += rec(level+1, 0);
        else {
            ans += max(money[level] + rec(level+1,1), rec(level+1, 0));
        }
        return dp[level][prev] = ans;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        money = nums;
        dp.resize(n+10, vector<int>({-1, -1}));
        return rec(0, 0);
    }
};
