// Problem Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        long long sharing = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            long long newSharing = dp[max(i - delay, 0)];
            long long forgetting = dp[max(i - forget, 0)];

            sharing += (newSharing - forgetting + mod) % mod;
            dp[i] = sharing;
        }

        long long ans = 0;
        for(int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
};