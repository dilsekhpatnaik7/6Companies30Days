// Problem Link: https://leetcode.com/problems/friends-of-appropriate-ages/description/

class Solution {
public:
    bool check(int x, int y) {
        return !((y <= 0.5 * x + 7) || (y > x) || (y > 100 && x < 100));
    }

    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> m;
        for(int i = 0; i < ages.size(); i++) {
            m[ages[i]]++;
        }

        int ans = 0;
        for(auto x: m) {
            for(auto y: m) {
                if(check(x.first, y.first)) ans += x.second * (y.second - (x.first == y.first));
            }
        }
        return ans;
    }
};