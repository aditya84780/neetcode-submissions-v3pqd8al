class Solution {
public:
int nn;
vector<int> dp;
    int rec(int level) {
        if (level < 0 || level > nn) return 0;
        if(level == nn) return 1;
        if(dp[level] != -1) return dp[level];
        int ans = 0;
        ans = rec(level+1) + rec(level+2);
        return dp[level] = ans;
    }
    int climbStairs(int n) {
        nn = n;
        dp.resize(n+1, -1);
        return rec(0);
    }
};
