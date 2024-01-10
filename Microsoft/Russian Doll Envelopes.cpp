// Problem Link: https://leetcode.com/problems/russian-doll-envelopes/description/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);

        vector<int> ans;
        int n = envelopes.size();
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(ans.begin(), ans.end(), envelopes[i][1]);

            if(it == ans.end()) ans.push_back(envelopes[i][1]);
            else *it = envelopes[i][1];
        }
        return ans.size();
    }
};