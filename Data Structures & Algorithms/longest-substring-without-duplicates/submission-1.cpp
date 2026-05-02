class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r =0;
        int maxSubstring = 0;

        unordered_map<char, int> m;

        while (r < s.size()) {
            if (m.find(s[r]) != m.end() && m[s[r]] >= l) {
                l = m[s[r]] + 1;
            }

            m[s[r]] = r;

            maxSubstring = max(maxSubstring, r -l+1);

            r++;
        }

        return maxSubstring;
    }
};
