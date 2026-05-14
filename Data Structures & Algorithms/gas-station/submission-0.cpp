class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            int currGas = 0;
            int ok = true;
            for (int j = 0; j <= n; j++) {
                int idx = (j+i) % n;
                currGas+=gas[idx];
                if (currGas < cost[idx]) {
                    ok = false;
                    break;
                }
                currGas-=cost[idx];
            }
            if (ok) return i;
        }
        return -1;
    }
};
