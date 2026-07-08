class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums[i] = 51;
            }
        }

        sort(nums.begin(), nums.end());
        while (nums.size() && nums.back() == 51) nums.pop_back();
        return nums.size();
    }
};