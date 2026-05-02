class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = nums.size() - 1;
            int need = -nums[i];
            while (r > l) {
                int sum = nums[l] + nums[r];
                if (sum == need) {
                    ans.push_back({nums[i], nums[r], nums[l]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) l++;
                }
                else if (sum < need) l++;
                else r--;
            }
        }

        return ans;
    }
};

//[-1,0,1,2,-1,-4]
// [-4, -1 , -1, 0, 1, 2]