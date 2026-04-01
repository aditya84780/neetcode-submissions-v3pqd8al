class Solution {
public:
int n;
string ss;
int dp[1010][1010];
    int rec(int l, int r) {
        if(l >=n || r<0) return 0;
        if(r-l+1 <= 1) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        ans = (ss[l] == ss[r])&&rec(l+1, r-1);
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
        int longest = 0;
        string ans;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                if(rec(i,j) && j-i+1 > longest) {
                    longest = j-i+1;
                    ans = s.substr(i, longest);
                }
            }
        }
        cout<<"longest: "<<longest;
        return ans;
    }
};
