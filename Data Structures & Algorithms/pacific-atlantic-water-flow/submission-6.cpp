class Solution {
private:
    int rows, cols;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int,int>>& q) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue; // must go uphill
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        queue<pair<int,int>> pacificQ, atlanticQ;

        // Pacific: top row and left col
        // Atlantic: bottom row and right col
        for (int r = 0; r < rows; r++) {
            pacific[r][0] = true;
            pacificQ.push({r, 0});
            atlantic[r][cols-1] = true;
            atlanticQ.push({r, cols-1});
        }
        for (int c = 0; c < cols; c++) {
            pacific[0][c] = true;
            pacificQ.push({0, c});
            atlantic[rows-1][c] = true;
            atlanticQ.push({rows-1, c});
        }

        bfs(heights, pacific, pacificQ);
        bfs(heights, atlantic, atlanticQ);

        vector<vector<int>> result;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (pacific[r][c] && atlantic[r][c])
                    result.push_back({r, c});

        return result;
    }
};