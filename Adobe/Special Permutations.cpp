// Problem Link: https://leetcode.com/problems/special-permutations/description/

class Solution {
public:
    int mod = 1e9+7;
    int solve(int prevIndex, int mask, int count, vector<int>& nums, vector<vector<int>>& dp) {
        if(count == nums.size()) return 1;
        if(dp[prevIndex][mask] != -1) return dp[prevIndex][mask];

        long long ways = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(mask & (1 << i)) continue;
            if(mask != 0 && nums[i] % nums[prevIndex] != 0 && nums[prevIndex] % nums[i] != 0) continue;

            ways = (ways + solve(i, mask | (1 << i), count + 1, nums, dp)) % mod; 
        }
        return dp[prevIndex][mask] = ways;
    }

    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>((1 << n), -1));

        return solve(0, 0, 0, nums, dp);
    }
};