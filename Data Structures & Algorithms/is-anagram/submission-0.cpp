class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> countS;
        for (char c : s) countS[c]++;
        for (char c : t) countS[c]--;
        for (auto& c : countS) {
            if (c.second != 0) return false;
        }
        return true;
    }
};
