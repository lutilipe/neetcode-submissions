class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int n:nums) m[n]++;
        vector<vector<int>> a;
        for (auto obj : m) {
            a.push_back({obj.second, obj.first});
        }
        sort(a.begin(),a.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int idx = a.size() - i - 1;
            ans.push_back(a[idx][1]);
        }

        return ans;
    }
};
