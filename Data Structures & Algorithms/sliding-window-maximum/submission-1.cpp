class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxDeque;
        int n = nums.size();
        int l = 0;
        int r = 0;

        vector<int> ans;

        while (r < n) {
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);

            if (r - l +1 >= k) {
                ans.push_back(nums[maxDeque.front()]);
                if (maxDeque.front() == l) maxDeque.pop_front();
                l++;
            }

            r++;
        }


        return ans;
    }
};
