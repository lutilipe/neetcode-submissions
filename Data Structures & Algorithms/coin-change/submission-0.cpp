class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> memo;
        sort(coins.begin(), coins.end());
        
        auto dp = [&](auto&& self, int c) {
            if (c == 0) return 0;
            if (memo.find(c) != memo.end()) return memo[c];
            
            int count = INT_MAX;
            
            for (int i = 0; i < coins.size(); i++) {
                if (c - coins[i] < 0) break;
                int rest = self(self, c-coins[i]);
                if (rest == -1) continue;
                count = min(count, 1 + rest);
            }
            
            return memo[c] = count == INT_MAX ? -1 : count;
        };
        
        return dp(dp, amount);
    }
};
