class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Cycle exists
        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};