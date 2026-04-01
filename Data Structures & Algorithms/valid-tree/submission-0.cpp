class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis, parent;
    bool hasCycle = false;
    void dfs(int node, int par, int col) {
        vis[node] = 1;
        parent[node] = par;
        for(auto v: g[node]) {
            if(!vis[v]) {
                dfs(v, node, col);
            } else if (v!=parent[node]) {
                hasCycle = true;
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) {
            return false;
        }
        g.resize(n);
        vis.resize(n, 0);
        parent.resize(n,-1);
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
                dfs(i, 0, col_num);
            }
        }
        if(col_num > 1 || hasCycle) {
            return false;
        }
        return true;
    }
};
