class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for (auto& prerequisite : prerequisites) {
            int dependent = prerequisite[0];
            int first = prerequisite[1];
            graph[first].push_back(dependent);
            indegree[dependent]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        if (!q.size()) return {};

        vector<int> ans;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            for (int dependent : graph[course]) {
                indegree[dependent]--;
                if (indegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};
