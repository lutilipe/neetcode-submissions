class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int n : nums) {
            count[n]++;
            if (count[n] > 1) return true;
        }

        return false;
    }
};