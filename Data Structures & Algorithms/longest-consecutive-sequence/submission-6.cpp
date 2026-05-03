class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        int maxSubsequence = 0;
        for (int num : nums) {
            m[num] = true;
        }
        for (int num : nums) {
            if (m.find(num-1) != m.end()) continue;
            int curr = num;
            int total = 0;
            while (m.find(curr) != m.end()) {
                total++;
                curr++;
            }
            maxSubsequence = max(maxSubsequence, total);
        }
        return maxSubsequence;
    }
};
