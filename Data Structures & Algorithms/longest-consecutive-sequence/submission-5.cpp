class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) s.insert(n);

        int l = 0;
        int ml = 0;

        for (int n : nums) {
            int curr = n;
            l++;
            if (s.find(curr-1) == s.end()) {
                while (s.find(curr+1) != s.end()) {
                    curr++;
                    l++;
                }
            }

            ml = max(ml, l);
            l = 0;
        } 

        return ml;
    }
};

// store if element exists in nums
// 