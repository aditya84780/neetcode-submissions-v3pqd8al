class Solution {
public:
int n;
string ss;
int dp[110];
    int rec(int level) {
        if(level < -1 || level >= n) return 0;
        if(level == 0 || level == -1) {
            return ss[0] != '0';
        }
        if(dp[level]!=-1) return dp[level];
        int ans = 0;
        if(ss[level] != '0') {
            ans += rec(level-1); 
        }
        if(ss[level-1] != '0') {
            if(stoi(ss.substr(level-1, 2)) <= 26)
            ans += rec(level-2);
        }
        return dp[level] = ans;
    }
    int numDecodings(string s) {
        ss = s;
        n = s.size();
        for(int i = 0; i< n; i++) {
            dp[i] =-1;
        }
        return rec(n-1);
    }
};
