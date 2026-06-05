class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);

        auto dp = [&](auto&& self, int i) {
            if (i >= s.size()) return true;
            if (memo[i] != -1) return memo[i] == 1;

            bool ok = false;

            for (string word : wordDict) {
                if (i + word.size() > s.size()) continue;

                if (s.substr(i, word.size()) != word) continue;

                if (self(self, i + word.size())) {
                    ok = true;
                    break;
                }
            }

            memo[i] = ok ? 1 : 0;
            return memo[i] == 1;
        };

        return dp(dp, 0);
    }
};
