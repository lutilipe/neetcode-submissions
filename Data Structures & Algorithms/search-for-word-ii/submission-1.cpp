class TrieNode {
    public:
        vector<TrieNode*> children = vector<TrieNode*>(26);
        string word = "";
};

class Solution {
    int m;
    int n;
    vector<string> ans;

    vector<vector<int>> directions = {
        {1,0},
        {0,1},
        {0,-1},
        {-1,0}
    };

    bool inBound(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, TrieNode* curr, int i, int j) {
        if (visited[i][j]) return;

        visited[i][j] = true;

        if (curr->word.size()) {
            ans.push_back(curr->word);
            curr->word = "";
        }

        for (auto& dir : directions) {
            int nextI = dir[0] + i;
            int nextJ = dir[1] + j;

            if (!inBound(nextI, nextJ)) continue;

            if (visited[nextI][nextJ]) continue;

            char c = board[nextI][nextJ];
            int parsedIndex = c - 'a';

            if (!curr->children[parsedIndex]) continue;

            dfs(board, visited, curr->children[parsedIndex], nextI, nextJ);
        }

        visited[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                int parsedIndex = c-'a';
                if (!curr->children[parsedIndex]) {
                    curr->children[parsedIndex] = new TrieNode(); 
                }
                curr = curr->children[parsedIndex];
            }
            curr->word = word;
        }

        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                TrieNode* curr = root;
                int parsedIndex = board[i][j] - 'a';
                if (curr->children[parsedIndex]) {
                    dfs(board, visited, curr->children[parsedIndex], i,j);
                }
            }
        }

        return ans;
    }
};
