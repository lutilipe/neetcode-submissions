class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target-position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), [](pair<int,double>& a, pair<int,double>& b) {
            return a.first > b.first;
        });

        stack<double> st;

        for (int i = 0; i < cars.size(); i++) {
            if (st.empty() || st.top() < cars[i].second) {
                st.push(cars[i].second);
            }
        }

        return st.size();
    }
};

// [0, 1, 4, 7]
// [1, 2, 2, 1]
// [10, 5, 3, 3]