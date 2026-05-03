class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCounter = 0;
        int totalMultiplicationValue = 1;

        for (int num : nums) {
            if (num == 0) {
                zeroCounter++;
                if (zeroCounter > 1) return vector<int>(nums.size(), 0);
                continue;
            }
            totalMultiplicationValue*=num;
        }

        vector<int> ans;

        for (int num : nums) {
            if (num == 0) {
                ans.push_back(totalMultiplicationValue);
            } else if (zeroCounter) {
                ans.push_back(0);
            } else {
                ans.push_back(totalMultiplicationValue/num);
            }
        }

        return ans;
    }
};
