class Solution {
public:
    unordered_map<char, unordered_set<char>> g;
    unordered_map<char, int> vis, indegree;
    string ans = "";
    bool has_cycle = false;
    void dfs(char node) {
                        cout<<"dfs on "<<node<<'\n';

        vis[node] = 1;
        cout<<"vis["<<node<<"] = "<<vis[node]<<'\n';
        for(auto v: g[node]) {
            if(vis[v] == 0) {
                dfs(v);
            } else if(vis[v] == 1) {
                has_cycle = true;
                break;
            }
        }
        ans+=node;
        vis[node] = 2;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        for(auto word: words) {
            for(auto c: word) {
                indegree[c] = 0;
                g[c];    
            }
        }
        for(int i = 0; i<n-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            int min_len = min(word1.size(), word2.size());
            if(word1.size() > word2.size() && word1.substr(0,min_len) == word2.substr(0,min_len)) {
                return "";
            } 
            for(int j = 0; j<min_len; j++) {
                if(word1[j]!=word2[j]) {
                    if(g[word1[j]].find(word2[j]) == g[word1[j]].end()) {
                        g[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break;
                }
            }
        }
        cout<<"graph:\n";
        for(auto b: g) {
            cout<<b.first<<": ";
            for(auto t: b.second) {
                cout<<t<<" ";
            }
            cout<<'\n';
        }
        cout<<"indeg:\n";
        for(auto v: indegree) {
            cout<<v.first<<" -> "<<v.second<<'\n';
        }
        queue<char> q;
        for(auto i: indegree) {
            if(i.second == 0) {
                q.push(i.first);
                ans+=i.first;
            }
        }
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            for(auto c: g[cur]) {
                indegree[c]--;
                if(indegree[c] == 0) {
                    ans+=c;
                    q.push(c);
                }
            }
        }
        cout<<ans<<'\n';
        if(ans.size()!=g.size()) {
            cout<<"cycle";
            return "";
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};
