class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int> memo;
        function<int(int)> dp = [&](int i) {
            if (i <= 2) return i;

            if (!memo[i]) {
                memo[i] = dp(i-1) + dp(i-2);
            }

            return memo[i];
        };

        return dp(n);
    }
};
