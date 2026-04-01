class Solution {
public:
    unordered_map<char, unordered_set<char>> g;
    unordered_map<char, int> vis;
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
        for(int i = 0; i<n-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            int min_len = min(word1.size(), word2.size());
            if(word1.size() > word2.size() && word1.substr(0,min_len) == word2.substr(0,min_len)) {
                return "";
            } 
            for(int j = 0; j<min_len; j++) {
                if(word1[j]!=word2[j]) {
                    g[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }
        cout<<"graph:\n";
        for(auto word: words) {
            for(auto c: word) {
                vis[c] = 0;
                g[c];
                
            }
        }
        for(auto b: g) {
            cout<<b.first<<": ";
            for(auto t: b.second) {
                cout<<t<<" ";
            }
            cout<<'\n';
        }
        cout<<"vis:\n";
        for(auto v: vis) {
            cout<<v.first<<" -> "<<v.second<<'\n';
        }
        for(auto v: vis) {
            if(v.second==0) {
                // cout<<"iteratively, vis["<<v.first<<"] = "<<
                dfs(v.first);
            }
        }
        if(has_cycle) {
            return "";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
