class Solution {
public:
// vector<vector<int>> g;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
vector<vector<vector<int>>> vis;
int n,m;
// void dfs(int x, int y, int col) {
//     vis[x][y][col] = 1;
    // for(int i = 0; i<4; i++) {
    //     int nx = x+dx[i];
    //     int ny = y+dy[i];
    //     if(nx>=0 && nx < n && ny>=0 && ny<m) {
    //         if(g[nx][ny] >= g[x][y]) {
    //             if(!vis[nx][ny][col]) {
    //                 dfs(nx, ny, col);
    //             }
    //         }
    //     }
//     }
// }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vis.resize(n, vector<vector<int>>(m, vector<int>(2, 0)));
        queue<pair<int, pair<int,int>>> q;
        for(int i = 0; i< n; i++) {
            vis[i][0][0] = 1;
            vis[i][m-1][1] = 1;
            q.push(make_pair(0, make_pair(i,0)));
            q.push(make_pair(1, make_pair(i, m-1)));
        }
        for(int j = 0; j< m; j++) {
            vis[0][j][0] = 1;
            vis[n-1][j][1] = 1;
            q.push(make_pair(0,make_pair(0,j)));
            q.push(make_pair(1, make_pair(n-1, j)));
        }
        while(!q.empty()) {
            auto cur = q.front();
            int col = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            q.pop();
            for(int i = 0; i<4; i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx < n && ny>=0 && ny<m) {
                    if(heights[nx][ny] >= heights[x][y]) {
                        if(!vis[nx][ny][col]) {
                            vis[nx][ny][col] = 1;
                            q.push(make_pair(col, make_pair(nx, ny)));
                        }
                    }
                }
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
