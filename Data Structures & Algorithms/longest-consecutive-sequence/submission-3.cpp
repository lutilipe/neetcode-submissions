class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int n : nums) m[n]++;

        int l = 0;
        int ml = 0;

        for (int n : nums) {
            if (m[n] <= 0) continue;
            int curr = n;
            l++;
            if (m.find(curr-1) == m.end()) {
                while (m.find(curr+1) != m.end() && m[curr+1] > 0) {
                    m[curr+1]--;
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