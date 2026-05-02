class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        for (int i = 0; i < temperatures.size(); i++) {
            int idx = -1;
            for (int j = i+1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    idx=j;
                    break;
                }
            }
            if (idx == -1) ans.push_back(0);
            else ans.push_back(idx-i);
        }
        return ans;
    }
};
//[30,38,30,36,35,40,28]
//[1, 4, 1, 2, 1, 0, 0]

// O(n2)
// for i in range(0, n):
//      for j in range(i+1,n):
            // if temp[j] > temp[i] ans.push