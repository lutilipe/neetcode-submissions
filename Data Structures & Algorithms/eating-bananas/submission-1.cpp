class Solution {
public:
    long long getHoursByK(vector<int>& piles, int k) {
        long long total = 0;
        for (int num : piles) {
            total+=ceil((double)num/k);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int m = -1;
        for (int num : piles) m = max(m,num);

        for (int k = 1; k <= m; k++) {
            long long hours = getHoursByK(piles, k);
            if (hours <= h) return k;
        }

        return m;
    }
};
