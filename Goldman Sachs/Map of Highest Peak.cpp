// Problem Link: https://leetcode.com/problems/map-of-highest-peak/description/

class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& ans) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == -1;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int distance = ans[row][col];
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(isValid(nrow, ncol, n, m, ans)) {
                    ans[nrow][ncol] = distance + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};