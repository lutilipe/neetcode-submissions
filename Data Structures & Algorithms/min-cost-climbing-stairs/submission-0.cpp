class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        unordered_map<int,int> memo;

        function<int(int)> dp = [&](int i) {
            if (i <= 1) return 0;

            if (!memo[i]) {
                memo[i] = min(dp(i-1) + cost[i-1], dp(i-2) + cost[i-2]);
            }

            return memo[i];
        };
        
        return dp(n);
    }
};

// dp(n)
// dp(i) = quanto eu gasto para estar naquele lugar
// dp(i) = min(dp(i-1) + nums[i-1], dp(i-2) + nums[i-2])
