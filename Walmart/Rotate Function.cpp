// Problem Link: https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long arraySum = 0, original = 0;

        for(int i = 0; i < nums.size(); i++) {
            arraySum += nums[i];
            original += (i * nums[i]);
        }

        long long maximumSum = original;
        for(int i = nums.size() - 1; i >= 0; i--) {
            original += arraySum - (nums.size() * nums[i]);
            maximumSum = max(original, maximumSum);
        }
        return maximumSum;
    }
};