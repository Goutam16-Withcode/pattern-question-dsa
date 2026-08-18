class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Courses having no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (int next : graph[node]) {

                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If all courses processed, no cycle
        return count == numCourses;
    }
};