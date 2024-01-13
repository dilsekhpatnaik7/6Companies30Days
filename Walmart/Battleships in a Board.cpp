// Problem Link: https://leetcode.com/problems/battleships-in-a-board/

class Solution {
public:
    bool isValid(int nrow, int ncol, vector<vector<char>>& board, vector<vector<int>>& vis) {
        return nrow >= 0 && nrow < board.size() && ncol >= 0 && ncol < board[0].size() && board[nrow][ncol] == 'X';
    }

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        int delRow[] = {0, +1};
        int delCol[] = {+1, 0};

        for(int i = 0; i < 2; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(isValid(nrow, ncol, board, vis)) dfs(nrow, ncol, board, vis);
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int battleShips = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'X' && !vis[i][j]) {
                    dfs(i, j, board, vis);
                    battleShips++;
                }
            }
        }
        return battleShips;
    }
};