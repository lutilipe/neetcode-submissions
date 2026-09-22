class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (string s : strs) {
            string curr = s;
            sort(curr.begin(), curr.end());
            m[curr].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& group : m) {
            vector<string> curr;
            for (string s : group.second) {
                curr.push_back(s);
            }
            ans.push_back(curr);
        }

        return ans;
    }
};
