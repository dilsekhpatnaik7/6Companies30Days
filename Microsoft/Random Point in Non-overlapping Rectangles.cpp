// Problem Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/

class Solution {
public:
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& rects) : rects(rects){   
    }
    
    vector<int> pick() {
        int ans = 0;
        vector<int> t;

        for(auto i: rects) {
            int area = (i[2] - i[0] + 1) * (i[3] - i[1] + 1);
            ans += area;

            if(rand() % ans < area) t = i;
        }

        int x = rand() % (t[2] - t[0] + 1) + t[0];
        int y = rand() % (t[3] - t[1] + 1) + t[1];

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */