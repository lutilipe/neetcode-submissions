class Solution {
    int m;
    int n;
public:
    vector<vector<int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    bool isInBound(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int orangesToRot = 0;
        m = grid.size();
        n = grid[0].size();
        
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) orangesToRot++;
                else if (grid[i][j] == 2) q.push({i,j});
            }
        }

        if (!orangesToRot) return 0;

        int time= 0;

        while (!q.empty() && orangesToRot > 0) {
            int s = q.size();
            while (s--) {
                vector<int> next = q.front();
                q.pop();
                int i = next[0];
                int j = next[1];

                for (auto& dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (isInBound(x,y) && grid[x][y]==1) {
                        q.push({x,y});
                        orangesToRot--;
                        grid[x][y] = 2;
                    }
                }
            }
            time++;
        }

        if (orangesToRot > 0) return -1;
        return time;
    }
};


/*
[
    [2,1,1],
    [0,1,1],
    [1,0,1]
]
*/