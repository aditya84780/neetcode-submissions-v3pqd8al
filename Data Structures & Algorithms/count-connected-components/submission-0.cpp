class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;

    void dfs(int node, int col) {
        vis[node] = 1;
        for(auto v: g[node]) {
            if(!vis[v]) {
                dfs(v, col);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.resize(n,0);
        for(auto e: edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int col_num = 0;
        for(int i = 0; i< n; i++) {
            if(!vis[i]) {
                col_num++;
                dfs(i, col_num);
            }
        }
        return col_num;
    }
};
