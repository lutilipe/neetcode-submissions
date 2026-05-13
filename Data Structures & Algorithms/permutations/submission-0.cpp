class Solution {
    vector<vector<int>> ans;
public:
    void permute(vector<int>& nums, int l) {
        if (l == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = l; i < nums.size(); i++) {
            swap(nums[i], nums[l]);
            permute(nums, l+1);
            swap(nums[i], nums[l]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0);
        return ans;
    }
};