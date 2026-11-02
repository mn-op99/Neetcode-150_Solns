class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjL(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &it : prerequisites) {

            int course = it[0];
            int pre = it[1];

            adjL[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neigh : adjL[node]) {

                indegree[neigh]--;

                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if(ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};