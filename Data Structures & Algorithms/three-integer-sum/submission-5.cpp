class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i +1;
            int r = nums.size() - 1;
            int diff = -nums[i];

            while (r > l) {
                
                int sum = nums[r] + nums[l];
                if (sum == diff) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1]) l++;
                }

                else if (sum < diff) l++;
                else r--; 
            }
        }

        return ans;
    }
};
