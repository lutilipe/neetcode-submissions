class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,double> time;
        for (int i = 0 ; i <position.size(); i++) {
            time[position[i]] = (target - position[i]) / (double)speed[i];
        }

        sort(position.begin(), position.end(), [](int a ,int b) {
            return a > b;
        });

        stack<int> st;

        for (int pos : position) {
            if (st.empty() || time[pos] > time[st.top()]) {
                st.push(pos);
            }
        }

        return st.size();
    }
};
