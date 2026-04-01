class Solution {
public:
int n;
string ss;
unordered_map<string, int> mp;
int dp[210][210];
    bool rec(int l, int r) {
        if(l<0 || r>=n || r-l+1 <=0) return 0;
        if(mp[ss.substr(l,r-l+1)]) return 1;
        if(dp[l][r] != -1) return dp[l][r];
        bool ans = false;
        for(int i = l; i<r; i++) {
            ans |= (rec(l,i) & rec(i+1, r));
        }
        return dp[l][r] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        ss = s;
        n = s.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                dp[i][j] = -1;
            }
        }
        for(auto word: wordDict) {
            mp[word] = 1;
        }
        int ans = 0;
        return rec(0,n-1);
    }
};
