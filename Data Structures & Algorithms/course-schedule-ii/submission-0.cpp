class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(vector<int>& pre : prerequisites){
            int u = pre[1];
            int v = pre[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> final;
        while(!q.empty()){
            int course = q.front();
            final.push_back(course);
            q.pop();
            for(int t : adj[course]){
                indegree[t]--;
                if(indegree[t] == 0){
                    q.push(t);
                }
            }
        }
        if (final.size() == numCourses) return final;
        else return {};
    }
};
