class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(vector<int>& pre : prerequisites){
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }
        vector<int>final;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            final.push_back(course);
            for(int i : adj[course]){
                indegree[i]--;
                if ( indegree[i] == 0) q.push(i);
            }
        }
        if(final.size() == numCourses) return final;
        else return {};
    }
};
