class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0 ,-1}};
        int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(m ,INF));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});
        while(!pq.empty()){
            auto [curr_max, k] = pq.top();
            int r = k.first;
            int c = k.second;
            pq.pop();
            if ( r == n - 1 && c == n - 1){
                return curr_max;
            }
            // if ( curr_max > dist[] )
            for(int d = 0; d < 4; d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n){
                    int new_max = max(grid[nr][nc], curr_max);
                    if (new_max < dist[nr][nc]){
                        dist[nr][nc] = new_max;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
    }
};
