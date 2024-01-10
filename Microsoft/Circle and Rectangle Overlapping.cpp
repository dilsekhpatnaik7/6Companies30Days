// Problem Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/description/

class Solution {
public:
    int solve(int a, int b, int x) {
        if(x < a) return abs(a - x);
        if(x > b) return abs(x - b);
        return 0;
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = solve(x1, x2, xCenter);
        int y = solve(y1, y2, yCenter);

        return (x*x + y*y) <= (radius*radius);
    }
};