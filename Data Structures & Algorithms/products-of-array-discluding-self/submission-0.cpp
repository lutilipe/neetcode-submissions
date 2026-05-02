class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int mul = 1;
        for (int n : nums) {
            if (n == 0) {
                zeroCount++;
                if (zeroCount > 1) {
                    return vector<int>(nums.size(), 0);
                }
                continue;
            }
            
            mul*=n;
        }

        vector<int> ans;

        for (int n : nums) {
            if (n == 0) ans.push_back(mul);
            else if (!zeroCount) {
                ans.push_back(mul/n);
            } else ans.push_back(0);
        }

        return ans;
        
    }
};

// [1, 2, 4, 6] ok
// [-1, 2, 4, 6] ok 
// [-1, -2, 4, 6] ok
// [1, 0, 4, 6] 
// [1, 0, 0, 6]; 0