// Problem Link: https://leetcode.com/problems/shopping-offers/description/

class Solution {
public:
    int solve(int index, vector<int> ds, vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<int, map<vector<int>, int>>& dp) {
        if(index == special.size()) {
            int total = 0;
            for(int i = 0; i < needs.size(); i++) {
                total += (needs[i] - ds[i]) * price[i];
            }
            return total;
        }

        if(dp.count(index) && dp[index].count(ds)) {
            return dp[index][ds];
        }

        int nonTake = solve(index + 1, ds, price, special, needs, dp);
        vector<int> copyds = ds;

        int take = 1e9;
        for(int i = 0; i < needs.size(); i++) {
            if(copyds[i] + special[index][i] <= needs[i]) {
                copyds[i] += special[index][i];
            } else {
                return dp[index][ds] = min(take, nonTake);
            }
        }

        take = special[index][price.size()] + solve(index, copyds, price, special, needs, dp);

        return dp[index][ds] = min(take, nonTake);
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<int, map<vector<int>, int>> dp;
        vector<int> ds(needs.size());

        return solve(0, ds, price, special, needs, dp);
    }
};