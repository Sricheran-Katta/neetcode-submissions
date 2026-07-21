class Solution {
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prevheight){
        int rows = heights.size();
        int cols = heights[0].size();
        if(r < 0 || r >= rows || c >= cols || c < 0 || visited[r][c] || prevheight > heights[r][c]){
            return;
        }
        visited[r][c] = true;
        dfs(heights, visited, r + 1, c, heights[r][c]);
        dfs(heights, visited, r - 1, c, heights[r][c]);
        dfs(heights, visited, r, c + 1, heights[r][c]);
        dfs(heights, visited, r, c - 1, heights[r][c]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> alt(rows, vector<bool> (cols, false)) ;
        vector<vector<bool>> pac(rows, vector<bool> (cols, false)) ;
        for(int c = 0; c < cols; c++){
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, alt, rows - 1, c, heights[rows - 1][c]);
        }
        for(int r = 0; r < rows; r++){
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, alt, r, cols - 1, heights[r][cols - 1]);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(alt[i][j] && pac[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
