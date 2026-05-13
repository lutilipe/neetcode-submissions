class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int i) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        helper(ans,nums,curr,i+1);
        curr.push_back(nums[i]);
        helper(ans,nums,curr,i+1);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,nums,curr,0);
        return ans;
    }
};
