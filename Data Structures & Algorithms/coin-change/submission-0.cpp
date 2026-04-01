class Solution {
public:
int n, a;
vector<int> coinArr;
int dp[10010][11];
    int rec(int left, int level) {
        if(level<0 || level >=n) return 1e9;
        if(left == 0) return 0;
        if(dp[left][level]!= -1) return dp[left][level];
        int ans = 1e9;
        if(left - coinArr[level] >= 0) {
            ans = min(1+rec(left - coinArr[level], level+1), 1+rec(left - coinArr[level], level));
        }
        ans = min(ans, rec(left, level+1));
        return dp[left][level] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        a = amount;
        coinArr = coins;
        n = coins.size();
        for(int i = 0; i<= amount; i++) {
            for(int j = 0;j <n; j++) {
                dp[i][j] = -1;
            }
        }
        if(rec(amount, 0) == 1e9) return -1;
        return rec(amount, 0);
    }
};
