class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        int t = 0;

        for (int n : nums) m[n]=true;

        for (int n : nums) {
            if (m.count(n-1) == 0) {
                int seq = 1;
                int curr = n;
                while (m.count(curr+1)) {
                    seq++;
                    curr++;
                }
                t=max(t,seq);
            }
        }

        return t;
    }
};
