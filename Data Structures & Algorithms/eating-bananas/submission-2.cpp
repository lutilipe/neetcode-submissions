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

        int l = 1;
        int r = m;

        while (r > l) {
            int k = l + (r-l)/2;
            int hours = getHoursByK(piles, k);
            if (hours > h) l = k+1;
            else r=k;
        }

        return l;
    }
};
