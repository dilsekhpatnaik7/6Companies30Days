// Problem Link: https://leetcode.com/problems/constrained-subsequence-sum/description/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        priority_queue<pair<int, int>> q;

        int ans = INT_MIN;
        dp[0] = nums[0];
        ans = max(ans, dp[0]);
        q.push({dp[0], 0});

        for(int i = 1; i < nums.size(); i++) {
            pair<int, int> t = q.top();
            while(t.second < i - k) {
                q.pop();
                t = q.top();
            }
            dp[i] = max(0, t.first) + nums[i];
            ans = max(ans, dp[i]);
            q.push({dp[i], i});
        }
        return ans;
    }
};