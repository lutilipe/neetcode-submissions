class Solution {
    int m;
    int n;

    vector<vector<int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
public:
    bool isOutOfBounds(int i, int j) {
        return i < 0 || j< 0 || i >= m || j >= n;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visitedPacific(m, vector<int>(n, 0));
        vector<vector<int>> visitedAtlantic(m, vector<int>(n, 0));

        auto dfs = [&](auto&& self, vector<vector<int>>& visited, int i, int j, int prevVal) {
            if (isOutOfBounds(i, j) || visited[i][j] || grid[i][j] < prevVal) return;
            visited[i][j] = true;

            for (auto& dir : directions) {
                int ni = dir[0] + i;
                int nj = dir[1] + j;
                self(self, visited, ni, nj, grid[i][j]);
            }
        };
        
        for (int c = 0; c < n; c++) {
            dfs(dfs, visitedPacific, 0, c, grid[0][c]);
            dfs(dfs, visitedAtlantic, m-1, c, grid[m-1][c]);
        }

        for (int r = 0; r < m; r++) {
            dfs(dfs, visitedPacific, r, 0, grid[r][0]);
            dfs(dfs, visitedAtlantic, r, n-1, grid[r][n-1]);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (visitedPacific[r][c] && visitedAtlantic[r][c]) ans.push_back({r,c});
            } 
        }
        
        return ans;
    }
};

// 0 = unvisited
// 1 = false
// 2 = true