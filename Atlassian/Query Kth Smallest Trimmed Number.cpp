// Problem Link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto i: queries) {
            int k = i[0];
            int trim = i[1];

            vector<pair<string, int>> trimmed;
            for(int i = 0; i < nums.size(); i++) {
                trimmed.push_back({nums[i].substr(nums[i].length() - trim), i});
            }

            sort(trimmed.begin(), trimmed.end());
            ans.push_back(trimmed[k - 1].second);
        }
        return ans;
    }
};