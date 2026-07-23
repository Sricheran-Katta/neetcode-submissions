class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& safe, vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == 'X' || safe[r][c] == 1) return;
        safe[r][c] = 1;
        dfs(r+1, c, safe, board);
        dfs(r, c+1, safe, board);
        dfs(r-1, c, safe, board);
        dfs(r, c-1, safe, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        if(rows == 0 || cols == 0) return;
        vector<vector<int>> safe(rows, vector<int> (cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'X') safe[i][j] = 1;
                else safe[i][j] = 0;
            }
        }
        for(int r = 0; r < rows; r++){
            if (board[r][0] == 'O' && safe[r][0] == 0) dfs(r, 0, safe, board);
            if (board[r][cols - 1] == 'O' && safe[r][cols - 1] == 0) dfs(r, cols - 1, safe, board);
        }
        for(int c = 0; c < cols; c++){
            if (board[0][c] == 'O' && safe[0][c] == 0) dfs(0, c, safe, board);
            if (board[rows - 1][c] == 'O' && safe[rows - 1][c] == 0) dfs(rows - 1, c, safe, board);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(safe[i][j] == 0) board[i][j] = 'X';
            }
        }
        return;
    }
};
