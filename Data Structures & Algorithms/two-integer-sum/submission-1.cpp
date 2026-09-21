class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int diff = target - n;
            if (m.count(diff)) return {m[diff], i};
            m[n] = i;
        }

        return {-1,-1};
    }
};
