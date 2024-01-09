// Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0, low = 0, high = nums.size() - 1;
        while(low < high) {
            count += nums[high] - nums[low];
            low++;
            high--;
        }
        return count;
    }
};