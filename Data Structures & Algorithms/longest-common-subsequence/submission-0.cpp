class Solution {
public:
int n1,n2;
string s1,s2;
int dp[1010][1010];
    int rec(int l, int r) {
        if(l >= n1 || r>= n2) return 0;
        if(l == n1-1 && r ==n2-1) {
            return s1[l] == s2[r];
        }
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        if(s1[l] == s2[r]) {
            ans = 1 + rec(l+1, r+1);
        } else {
            ans = max(rec(l+1, r), rec(l, r+1));
        }
        return dp[l][r] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        s1= text1;
        s2 = text2;
        n1 = s1.size();
        n2 = s2.size();
        for(int i = 0; i< n1; i++) {
            for(int j = 0; j<n2; j++) {
                dp[i][j] = -1;
            }
        }
        return rec(0,0);
    }
};
