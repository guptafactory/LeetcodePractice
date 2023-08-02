class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0), ans;
        queue<int> que;
        for(auto pr: prerequisites) {
            adj[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                ans.push_back(i);
            }
        }
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            for(int adjNode: adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    que.push(adjNode);
                    ans.push_back(adjNode);
                }
            }
        }
        if(ans.size() != numCourses) ans.clear(); 
        return ans;
    }
};