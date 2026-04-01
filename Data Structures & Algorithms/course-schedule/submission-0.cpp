class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    bool hasCycle = false;
    void dfs(int node) {
        vis[node] = 1;
        for(auto v: g[node]) {
            if(vis[v] == 0) {
                dfs(v);
            } else if(vis[v] == 1) {
                hasCycle = true;
            }
        }
        vis[node] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        vis.resize(numCourses, 0);
        for(auto edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            g[u].push_back(v);
        }
        for(int i = 0; i<numCourses; i++) {
            if(vis[i]==0) {
                dfs(i);
            }
        }
        return !hasCycle;
    }
};
