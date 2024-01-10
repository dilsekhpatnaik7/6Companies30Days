// Problem Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

class Solution {
public:
    bool check(int low, int high, int n, vector<int>& nums) {
        int prev = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(i >= low && i <= high) continue;

            if(nums[i] <= prev) return false;
            prev = nums[i];
        }
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(check(i, j, n, nums)) count++;
            }
        }
        return count;
    }
};