class Solution {
    vector<vector<int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
public:

    void dfs(
        vector<vector<int>>& grid,
        vector<vector<bool>>& visited,
        int i,
        int j,
        int& count
    ) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) return;

        visited[i][j] = true;

        count+=1;

        for (auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];

            dfs(grid,visited,x,y, count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int count = 0;
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(grid,visited,i,j, count);
                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;
    }
};
