
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for (int num : nums) count[num]++;

        auto comp = [&](int a, int b) {
            return count[a] > count[b]; 
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (auto& numCount : count) {
            if (pq.size() < k) pq.push(numCount.first);
            else {
                int top = pq.top();
                if (count[top] < numCount.second) {
                    pq.pop();
                    pq.push(numCount.first);
                }
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            ans.push_back(top);
        }

        return ans;
    }
};
