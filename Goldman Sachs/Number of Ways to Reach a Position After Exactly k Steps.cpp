// Problem Link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/

class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int start, int end, int k, vector<vector<int>>& dp) {
        if(k == 0) return start == end;
        if(dp[start + 1000][k] != -1) return dp[start + 1000][k];

        int left = solve(start - 1, end, k - 1, dp);
        int right = solve(start + 1, end, k - 1, dp);

        return dp[start + 1000][k] = (left + right) % mod;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3005, vector<int>(1005, -1));

        return solve(startPos, endPos, k, dp);
    }
};