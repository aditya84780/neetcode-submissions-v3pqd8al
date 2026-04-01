class Solution {
public:
int n;
string ss;
unordered_map<string, int> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        ss = s;
        n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i = n-1; i>=0; i--) {
            for(auto word: wordDict) {
                if(n-i>=word.size() && word == s.substr(i, word.size())) {
                    dp[i] |= dp[i + word.size()];
                    // if(dp[i]) break;
                }
            }
        }
        return dp[0];
    }
};
