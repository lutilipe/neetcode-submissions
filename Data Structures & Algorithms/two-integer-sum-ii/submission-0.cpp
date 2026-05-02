class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (r > l) {
            if (nums[l] + nums[r] == target) return {l+1, r+1};
            if (nums[l] + nums[r] < target) l++;
            else r--;
        }

        return {-1,-1};
    }
};


/* 
numbers = [1,2,3,4], target = -3
[-1,-2,-3,-4]
  R        L

if (nums[l] + nums[r] == target) return {l, r};
if (nums[l] + nums[r] < target) l++;
else r--;

*/