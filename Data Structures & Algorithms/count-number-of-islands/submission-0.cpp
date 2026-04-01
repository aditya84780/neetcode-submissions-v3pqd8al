class Solution {
public:
    vector<int> dx = {1, 0 , -1, 0};
    vector<int> dy = {0 , -1, 0, 1};
    vector<vector<char>> dem;
    vector<vector<int>> vis;
    int n,m;
    void dfs(int x, int y, int col_num) {
        vis[x][y] = col_num;
        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx < n && ny>=0 && ny<m) {
                if(!vis[nx][ny] && dem[nx][ny] == '1') {
                    dfs(nx, ny, col_num);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dem = vector<vector<char>>(grid);
        vis.resize(n, vector<int>(m, 0));
        int col_num = 0;
        for(int i = 0; i< n; i++) {
            for(int j = 0; j< m; j++) {
                if(!vis[i][j] && dem[i][j] == '1') {
                    col_num++;
                    dfs(i, j, col_num);
                }
            }
        }
        return col_num;
    }
};
