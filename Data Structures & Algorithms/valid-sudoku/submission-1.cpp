class Solution {
public:
    int getBox(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool colMap[9][9] = {false};
        bool rowMap[9][9] = {false};
        bool boxMap[9][9] = {false};

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == '.') continue;
                int n = board[row][col] - '1';
                int box = getBox(row, col);
                if (colMap[col][n] || rowMap[row][n] || boxMap[box][n]) return false;

                colMap[col][n] = true;
                rowMap[row][n] = true;
                boxMap[box][n] = true;
            }
        }
        return true;
    }
};

