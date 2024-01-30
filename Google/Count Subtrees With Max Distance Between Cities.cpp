// Problem Link: https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/description/

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX / 2 - 1));
        for(auto e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            graph[u][v] = graph[v][u] = 1;
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        
        vector<int> res(n-1, 0);
        for(int sub = 0; sub < (1 << n); sub++) {
            int nodes = __builtin_popcount(sub);
            int edges = 0;
            int dist = 0;

            for(int i = 0; i < n; i++)
                if(sub & (1 << i)) {
                    for(int j = i + 1; j < n; j++) 
                        if(sub & (1 << j)) {
                            edges += graph[i][j] == 1;
                            dist = max(dist, graph[i][j]);
                    }
            }
            if(edges == nodes - 1 && dist > 0) res[dist - 1]++;
        }
        return res;
    }
};