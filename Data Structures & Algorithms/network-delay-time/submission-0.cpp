class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(vector<int>& t : times){
            int u = t[0];
            int v = t[1];
            int time = t[2];
            adj[u].push_back({v, time});
        }
        int INF = 1e9;
        vector<int> dist(n+1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [curr_dist, u] = pq.top();
            pq.pop();
            if (curr_dist > dist[u]){continue;}
            for (auto& neighbour : adj[u]){
                int v = neighbour.first;
                int time = neighbour.second;
                if (curr_dist + time < dist[v]){
                    dist[v] = curr_dist + time;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxi = 0;
        for (int i = 1; i < n+1; i++){
            if (dist[i] == INF) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
