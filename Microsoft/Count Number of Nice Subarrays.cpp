// Problem Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto &i: nums) {
            i = i % 2;
        }

        unordered_map<int, int> m;
        m[0] = 1;
        int currentSum = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            if(m.count(currentSum - k)) ans += m[currentSum - k];
            m[currentSum]++;
        }
        return ans;
    }
};