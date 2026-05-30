class Solution {
    int m;
    int n;

    bool isOutOfBounds(int i, int j) {
        return i < 0 || i >= m || j < 0 || j >= n;
    }

    vector<vector<int>> directions = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i,j});
            }
        }

        if (q.empty()) return;

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();

            moves++;
            while (size--) {
                auto [i,j] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int px = dir[0] + i;
                    int py = dir[1] + j;

                    if (isOutOfBounds(px, py)) continue;

                    if (grid[px][py] != INT_MAX) continue;

                    grid[px][py] = moves;

                    q.push({px,py});
                }
            } 
        }
    }
};
