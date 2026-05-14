class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> memo;
        int n = nums.size();

        function<int(int)> dp = [&](int i) {
            if (i == 0) return nums[0];
            if (i == 1) return max(nums[1], nums[0]);

            if (!memo[i]) {
                memo[i] = max(dp(i-1), dp(i-2) + nums[i]);
            }

            return memo[i];
        };

        return dp(n-1);
    }
};

// dp(i) = max(dp(i-1), dp(i-2) + nums[i]);