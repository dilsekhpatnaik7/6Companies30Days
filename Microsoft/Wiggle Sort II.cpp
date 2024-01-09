// Problem Link: https://leetcode.com/problems/wiggle-sort-ii/description/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 0;
        priority_queue<int> q(nums.begin(), nums.end());

        while(i < n && !q.empty()) {
            nums[i] = q.top();
            q.pop();
            i += 2;
        }
        while(j < n && !q.empty()) {
            nums[j] = q.top();
            q.pop();
            j += 2;
        }
    }
};