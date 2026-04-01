class Solution {
public:
    int n;
    int dp[1010][1010];
    int rec(int l, int r, string s) {
        if(l < 0 || r > n-1 || r-l+1 < 0) return 0;
        if(r-l+1 <= 1) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = (s[l]==s[r]) && rec(l+1, r-1, s);
        return dp[l][r] = ans;
    }
    int countSubstrings(string s) {
        n = s.size();
        int ans = 0;
        for(int i = 0; i< n; i++) {
            for (int j = i; j<n; j++) {
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i< n; i++) {
            for (int j = i; j<n; j++) {
                ans += rec(i,j, s);
            }
        }
        return ans;
    }
};
