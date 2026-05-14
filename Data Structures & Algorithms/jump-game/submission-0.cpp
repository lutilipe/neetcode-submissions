class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJumpIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxJumpIdx) return false;
            maxJumpIdx = max(maxJumpIdx, i+nums[i]);
        }

        return true;
    }
};
