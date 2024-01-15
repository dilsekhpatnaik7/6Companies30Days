// Problem Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        int pairCount = 0;
        for(auto i: m) {
            if((!k && i.second > 1) || (k && m.count(i.first + k))) pairCount++;
        }
        return pairCount;
    }
};