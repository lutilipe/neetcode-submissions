class Solution {
    int m, n;
public:
    int getQuadrant(int i, int j) {
        return (i/3)*3 + (j/3);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,vector<pair<int,int>>> pos;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (pos.count(c) > 0) {
                    for (auto& p : pos[c]) {
                        if (p.first == i) return false;
                        if (p.second == j) return false;
                        if (getQuadrant(i, j) == getQuadrant(p.first, p.second)) return false;
                    }
                }

                pos[c].push_back({i,j});
            }
        }

        return true;
    }
};
