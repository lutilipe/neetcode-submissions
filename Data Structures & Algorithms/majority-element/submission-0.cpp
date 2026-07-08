class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        bool isPair = n % 2 == 0;
        int half = isPair ? n /2 -1 : n/2;

        for (int num : nums) {
            count[num]++;
            if (count[num] > half) return num;
        }

        return -1;
    }
};