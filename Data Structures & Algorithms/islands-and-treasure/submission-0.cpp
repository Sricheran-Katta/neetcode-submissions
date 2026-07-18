class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        if (q.empty()) return;
        int time = 0;
        vector<int> dirR = {1, -1, 0, 0};
        vector<int> dirC = {0, 0, 1, -1};
        while(!q.empty()){
            int level_size = q.size();
            time++;
            for(int i = 0; i < level_size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int d = 0; d < 4; d++){
                    int nextr = r + dirR[d];
                    int nextc = c + dirC[d];
                    if (nextr < rows && nextr >= 0 && nextc < cols && nextc >= 0 && grid[nextr][nextc] == INT_MAX){
                        grid[nextr][nextc] = time;
                        q.push({nextr, nextc});
                    }
                }
            }
        }
    }
};
