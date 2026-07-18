class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == 1){
                    fresh_count++;
                }
                else if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        if (fresh_count == 0) return 0;
        int time = 0;
        vector<int> dirR = {1, -1, 0, 0};
        vector<int> dirC = {0, 0, 1, -1};
        while(!q.empty()){
            int current_size = q.size();
            bool rotted_this_batch = false;
            for(int i = 0; i < current_size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int d = 0; d < 4; d++){
                    int nextr = r + dirR[d];
                    int nextc = c + dirC[d];
                    if(nextr < rows && nextr >= 0 && nextc < cols && nextc >= 0 && grid[nextr][nextc] == 1){
                        grid[nextr][nextc] = 2;
                        fresh_count--;
                        rotted_this_batch = true;
                        q.push({nextr, nextc});
                    }
                }
            }
            if (rotted_this_batch) time++;
        }
        if (fresh_count > 0) return -1;
        else return time;
    }
};
