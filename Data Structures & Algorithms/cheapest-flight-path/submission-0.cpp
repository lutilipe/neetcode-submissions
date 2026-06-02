class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto& flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].push_back({ price, to });
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vector<int> stops(n, INT_MAX);
        
        pq.push({ 0, src, 0 });
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int price = curr[0];
            int node = curr[1];
            int stop = curr[2];
            
            if (stop >= stops[node] || stop > k+1) continue;
            stops[node] = stop;
            if (node == dst) return price;
            
            for (auto [childPrice, childNode] : graph[node]) {
                int newPrice = childPrice + price;
                pq.push({ newPrice, childNode, stop+1 });
            }
        }
        
        return -1;
    }
};
