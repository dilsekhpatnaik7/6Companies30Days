// Problem Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        if(!left.empty()) ans = *max_element(left.begin(), left.end());
        if(!right.empty()) ans = max(ans, n - *min_element(right.begin(), right.end()));

        return ans;
    }
};