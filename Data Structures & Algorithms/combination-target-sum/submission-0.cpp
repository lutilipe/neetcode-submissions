class Solution {
public:
    void helper(
        vector<vector<int>>& ans,
        vector<int>& nums,
        int target,
        vector<int>& curr,
        int sum,
        int i
    ) {
        if (i >= nums.size() || sum >= target) {
            if (sum == target) {
                ans.push_back(curr);
            }
            return;
        }

        curr.push_back(nums[i]);
        helper(ans,nums,target,curr, sum+nums[i],i);
        curr.pop_back();

        helper(ans,nums,target,curr, sum,i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(ans, nums, target, curr, 0, 0);

        return ans;

    }
};
