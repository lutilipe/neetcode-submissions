class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> m;
        for (int n : nums ){
            if (m.count(n)) return true;
            m[n] = true;
        }
        return false;
    }
};