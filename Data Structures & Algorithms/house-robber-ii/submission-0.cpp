class Solution {
public:
int n;
vector<int> numArr;
int dp[100][2][2];
int rec(int level, int prev, int first) {
    if(level < 0 || level >= n) return 0;
    if(level == n-1) {
        if(prev == 1 || first == 1) {
            return 0;
        }
        return numArr[n-1];
    }
    if(dp[level][prev][first] != -1) return dp[level][prev][first];
    int ans = 0;
    if(level == 0) {
        if(first == 1) {
            ans += numArr[level] + rec(level+1, 1, first);
        } else {
            ans += rec(level+1, 0, 0);
        }
    } else {
        if(prev == 1) ans += rec(level + 1, 0, first);
        else {
            ans += max(numArr[level] + rec(level+1, 1, first), rec(level + 1, 0, first));
        }
    }
    
    return dp[level][prev][first] = ans;
}
    int rob(vector<int>& nums) {
         n = nums.size();
        numArr = nums;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j< 2; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        return max(rec(0, 0, 0) , rec(0, 0, 1));
    }
};
