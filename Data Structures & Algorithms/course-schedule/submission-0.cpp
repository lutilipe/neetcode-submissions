class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> al(numCourses);
        vector<int> inDegree(numCourses);

        for (auto& prerequisite : prerequisites) {
            int from = prerequisite[1];
            int to = prerequisite[0];
            al[from].push_back(to);
            inDegree[to]++;
        }

        queue<int> q;
        for (int i  = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        int coursesTaken = q.size();

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (auto& dependent : al[course]) {
                inDegree[dependent]--;
                if (inDegree[dependent] == 0) {
                    q.push(dependent);
                    coursesTaken++;
                }
            }
        }

        return coursesTaken == numCourses;
    }
};
