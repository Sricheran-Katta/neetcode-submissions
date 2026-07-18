class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> final;
        while(!q.empty()){
            int level_size = q.size();
            for(int i = 0; i < level_size; i++){
                int c = q.front();
                final.push_back(c);
                q.pop();
                if(!adj[c].empty()){
                    for(int k : adj[c]){
                        indegree[k]--;
                        if (indegree[k] == 0) q.push(k);
                    }
                }
            }
        }
        return final.size() == numCourses;
    }
};
