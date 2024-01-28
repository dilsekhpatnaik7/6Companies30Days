// Problem Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e5));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(auto &edge : edges) {
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int city = -1, counting = n;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) count++;
            }
            if(count <= counting) {
                counting = count;
                city = i;
            }
        }
        return city;
    }
};