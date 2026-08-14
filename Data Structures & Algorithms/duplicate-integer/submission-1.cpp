class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map<int,bool> m;
       for (int num : nums) {
            if (m[num]) return true;
            m[num]= true;
       }
       return false;
    }
};