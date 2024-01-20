// Problem Link: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int n = specialRoads.size();
        int startX = start[0], startY = start[1], endX = target[0], endY = target[1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dp(n, 1e9);

        for(int i = 0; i < n; i++) {
            q.push({abs(endX - specialRoads[i][2]) + abs(endY - specialRoads[i][3]), i});
        }

        while(!q.empty()) {
            int cost = q.top().first;
            int index = q.top().second;
            q.pop();

            if(dp[index] != 1e9) continue;

            dp[index] = min(dp[index], cost);
            for(int j = 0; j < n; j++) {
                if(j == index) continue;
                q.push({cost + specialRoads[index][4] + abs(specialRoads[j][2] - specialRoads[index][0]) + abs(specialRoads[j][3] - specialRoads[index][1]), j});
            }
        }

        int ans = abs(startX - endX) + abs(startY - endY);
        for(int i = 0; i < n; i++) {
            ans = min(ans, abs(startX - specialRoads[i][0]) + abs(startY - specialRoads[i][1]) + specialRoads[i][4] + dp[i]);
        }

        return ans;
    }
};