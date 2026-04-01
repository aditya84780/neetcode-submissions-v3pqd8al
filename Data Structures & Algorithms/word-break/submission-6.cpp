class Solution {
public:
int n;
string ss;
unordered_map<string, int> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        ss = s;
        n = s.size();
        queue<int> q;
        for(auto word: wordDict) {
            mp[word] = 1;
        }
        int it = 0;
        for(auto word: wordDict) {
            if(word == s.substr(it, word.size())) {
                q.push(it+word.size());
            }
        }
        vector<int> vis(n+1, 0);
        while(!q.empty()) {
            it = q.front();
            q.pop();
            if(it == n) break;
            for(auto word: wordDict) {
                if(word == s.substr(it, word.size())) {
                    if(it+word.size() <=n && !vis[it+word.size()])
                    q.push(it+word.size());
                    vis[it+word.size()] = 1;
                }
            }
        }
        return it == n;
    }
};
