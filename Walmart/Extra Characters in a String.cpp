// Problem Link: https://leetcode.com/problems/extra-characters-in-a-string/description/

class Solution {
public:
    int solve(int start, int end, string s, unordered_map<string, int>& m, vector<int>& dp) {
        if (end >= s.size()) return end - start;
        if (dp[start] != -1) return dp[start];

        string temp = s.substr(start, end - start + 1);
        int pick = 1e9;

        if(m.find(temp) != m.end()) {
            pick = solve(end + 1, end + 1, s, m, dp);
        }

        int notPick = solve(start, end + 1, s, m, dp);
        int skip = end - start + 1 + solve(end + 1, end + 1, s, m, dp);

        return dp[start] = min({pick, notPick, skip});
    }    

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int> m;
        for(auto i: dictionary) {
            m[i]++;
        }
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, 0, s, m, dp);
    }
};