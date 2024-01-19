// Problem Link: https://leetcode.com/problems/matrix-cells-in-distance-order/description/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                ans.push_back({i, j, abs(i - rCenter) + abs(j - cCenter)});
            }
        }
        sort(ans.begin(), ans.end(), comp);
        for(vector<int>& t: ans) {
            t.pop_back();
        }

        return ans;
    }
};