// Problem Link: https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/

class Solution {
public:
    int mod = 1e9+7;
    long long getMask(long long n, vector<int>& primes) {
        long long mask = 0;

        for(int i = 0; i < 10; i++) {
            int t = 0;
            while(n % primes[i] == 0) {
                t++;
                n /= primes[i];
            }
            if(t > 1) return -1;
            if(t == 1) mask |= (1 << (i + 1));
        }
        return mask;
    }

    long long solve(int index, long long prodMask, vector<int>& nums, vector<int>& primes, vector<vector<long long>>& dp) {
        if(index >= nums.size()) return 1;
        if(dp[index][prodMask] != -1) return dp[index][prodMask];

        long long mask = getMask(nums[index], primes);
        long long ans = solve(index + 1, prodMask, nums, primes, dp);

        if((prodMask & mask) == 0) {
            ans = (ans + solve(index + 1, prodMask | mask, nums, primes, dp)) % mod;
        }

        return dp[index][prodMask] = ans;
    }

    int squareFreeSubsets(vector<int>& nums) {
        vector<vector<long long>> dp(1111, vector<long long>(2048, -1));
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        return (solve(0, 1, nums, primes, dp) - 1 + mod) % mod;
    }
};