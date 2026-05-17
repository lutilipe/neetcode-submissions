class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> al(n);
        for (auto& time : times) {
            int from = time[0] - 1;
            int to = time[1] - 1;
            int timeTaken = time[2];

            al[from].push_back({timeTaken, to});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k-1});

        vector<int> dist(n, INT_MAX);
        vector<int> visited(n);

        dist[k-1] = 0;

        while (!pq.empty()) {
            auto [time, from] = pq.top();
            pq.pop();
            if (time > dist[from]) continue;
            visited[from] = true;

            for (auto& [childTime, child] : al[from]) {
                if (visited[child]) continue;
                int timeToReachChild = childTime + dist[from];
                if (timeToReachChild < dist[child]) {
                    dist[child] = timeToReachChild;
                    pq.push({timeToReachChild, child});
                }
            }
        }

        int time = INT_MIN;

        for (int node : dist) {
            if (node == INT_MAX) {
                return -1;
            }
            time = max(time, node);
        }

        return time;
    }
};
