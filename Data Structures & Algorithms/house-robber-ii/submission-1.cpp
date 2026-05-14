class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        function<int(int,int,int)> solve = [&](int ii, int l, int r) {
            unordered_map<int,int> memo;
            function<int(int)> dp = [&](int i) {
                if (i < l || i > r) return 0;

                if (!memo[i]) {
                    memo[i] = max(dp(i+1), dp(i+2) + nums[i]);
                }

                return memo[i];
            };

            return dp(ii);
        };

        return max(solve(0, 0, nums.size() - 2), solve(1, 1, nums.size() - 1));
    }
};

// dp(i) = max(dp(i+1), dp(i+2) + nums[i])