class Solution {
public:
vector<vector<int>> pac, atl, g;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
vector<vector<vector<int>>> vis;
int n,m;
void dfs(int x, int y, int col) {
    vis[x][y][col] = 1;
    for(int i = 0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx < n && ny>=0 && ny<m) {
            if(g[nx][ny] >= g[x][y]) {
                if(!vis[nx][ny][col]) {
                    dfs(nx, ny, col);
                }
            }
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        g = heights;
        n = heights.size();
        m = heights[0].size();
        pac.resize(n, vector<int>(m, 0));
        atl.resize(n, vector<int>(m, 0));
        vis.resize(n, vector<vector<int>>(m, vector<int>(2, 0)));
        for(int i = 0; i< n; i++) {
            if(!vis[i][m-1][1]) {
                dfs(i, m-1, 1);
            }
            if(!vis[i][0][0]) {
                dfs(i, 0, 0);
            }
        }
        for(int j = 0; j< m; j++) {
            if(!vis[0][j][0]) {
                dfs(0, j, 0);
            }
            if(!vis[n-1][j][1]) {
                dfs(n-1, j, 1);
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(vis[i][j][0] & vis[i][j][1]) {
                    ans.push_back(vector<int>({i,j}));
                }
            }
        }
        return ans;
    }
};
