class Solution {
    unordered_map<int,unordered_map<char,bool>> colMap;
    unordered_map<int,unordered_map<char,bool>> rowMap;
    unordered_map<int,unordered_map<char,bool>> boxMap;

public:
    int getBox(int i, int j) {
        if (i >= 0 && i <= 2) {
            if (j >= 0 && j <= 2) {
                return 0;
            } else if (j >= 3 && j <= 5) {
                return 1;
            } else {
                return 2;
            }
        } else if (i >= 3 && i <= 5) {
            if (j >= 0 && j <= 2) {
                return 3;
            } else if (j >= 3 && j <= 5) {
                return 4;
            } else {
                return 5;
            }
        } else {
            if (j >= 0 && j <= 2) {
                return 6;
            } else if (j >= 3 && j <= 5) {
                return 7;
            } else {
                return 8;
            }
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            colMap[i] = unordered_map<char,bool>();
            rowMap[i] = unordered_map<char,bool>();
            boxMap[i] = unordered_map<char,bool>();
        }

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                char n = board[row][col];
                if (n == '.') continue;
                int box = getBox(row, col);
                if (colMap[col].find(n) != colMap[col].end()) return false;
                if (rowMap[row].find(n) != rowMap[row].end()) return false;
                if (boxMap[box].find(n) != boxMap[box].end()) return false;

                colMap[col][n] = true;
                rowMap[row][n] = true;
                boxMap[box][n] = true;
            }
        }
        return true;
    }
};

