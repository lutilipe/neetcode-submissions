class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            maxSum = max({maxSum, num});
            sum += num;

            if (sum < 0) sum = 0;
            else maxSum=max(maxSum, sum);
        }

        return maxSum;
    }
};
