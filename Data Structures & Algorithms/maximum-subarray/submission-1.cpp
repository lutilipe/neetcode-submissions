class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            if (sum < 0) sum = 0;
            sum += num;
            maxSum = max({maxSum, sum});
        }

        return maxSum;
    }
};
