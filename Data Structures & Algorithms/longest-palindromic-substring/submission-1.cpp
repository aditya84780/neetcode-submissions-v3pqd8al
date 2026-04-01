class Solution {
public:
int n;
string ss;
int dp[1010][1010];
    int rec(int l, int r) {
        if(l >=n || r<0) return 0;
        if(r-l+1 == 1) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        ans = max(rec(l, r-1), rec(l+1, r));
        if(ss[l] == ss[r]) {
            if(rec(l+1, r-1) == r-l-1)
            ans = max(ans, 2 + rec(l+1, r-1));
        }
        return dp[l][r] = ans;
    }
    string longestPalindrome(string s) {
        n = s.size();
        ss = s;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                dp[i][j] = -1;
            }
        }
        int longest = rec(0, n-1);
        int st = 0;
        for(int i = 0; i<n; i++) {
            int pali = 1;
            for(int j = 0; j<longest/2; j++) {
                if(s[i+j]!=s[i+longest-j-1]) {
                    pali = 0;
                    break;
                }
            }
            if(pali) {
                st = i;
                break;
            }
        }
        cout<<"st: "<<st<<" longest: "<<longest;
        return s.substr(st, longest);
    }
};
