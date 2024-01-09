// Problem Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

class Solution {
public:
    void bfs(int src, vector<pair<long long, long long>> adj[], vector<vector<long long>>& dist) {
        vector<long long> cost(26, 1e18);
        cost[src] = 0;

        set<pair<int, int>> s;
        for(int i = 0; i < 26; i++) {
            s.insert({cost[i], i});
        }

        while(!s.empty()) {
            int current = s.begin()->second;
            s.erase(s.begin());

            for(auto [adjacent, weight]: adj[current]) {
                if(cost[current] + weight < cost[adjacent]) {
                    cost[adjacent] = cost[current] + weight;
                    s.insert({cost[adjacent], adjacent});
                }
            }
        }
        dist[src] = cost;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<long long, long long>> adj[26];
        for(int i = 0; i < cost.size(); i++) {
            int src = original[i] - 'a';
            int dest = changed[i] - 'a';

            adj[src].push_back({dest, cost[i]});
        } 

        vector<vector<long long>> dist(26, vector<long long>(26));
        for(int i = 0; i < 26; i++) {
            bfs(i, adj, dist);
        }

        long long ans = 0;
        for(int i = 0; i < source.length(); i++) {
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            if(dist[src][dest] == 1e18) return -1;
            ans += dist[src][dest];
        }
        return ans;
    }
};