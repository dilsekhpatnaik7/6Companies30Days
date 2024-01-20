// Problem Link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lostMatches;
        vector<vector<int>> ans(2);

        for(auto i: matches) {
            lostMatches[i[1]]++;
            lostMatches[i[0]] = lostMatches[i[0]];
        }

        for(auto [i, count]: lostMatches) {
            if(count == 0) ans[0].push_back(i);
            if(count == 1) ans[1].push_back(i);
        }
        return ans;
    }
};