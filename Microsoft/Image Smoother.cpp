// Problem Link: https://leetcode.com/problems/image-smoother/description/

class Solution {
public:
    int bfs(int row, int col, int n, int m, vector<vector<int>>& img) {
        int sum = 0, count = 0;

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int nrow = row + i;
                int ncol = col + j;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    sum += img[nrow][ncol];
                    count++;
                }
            }
        }
        return sum / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = bfs(i, j, n, m, img);
            }
        }
        return ans;
    }
};