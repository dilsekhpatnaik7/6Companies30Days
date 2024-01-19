// Problem Link: https://leetcode.com/problems/construct-the-longest-new-string/description/

class Solution {
public:
    int longestString(int x, int y, int z) {
        int aStart = 0, bStart = 0;
        int X = x, Y = y;

        while(X && Y) {
            aStart += 2;
            bStart += 2;
            X--, Y--;
        }

        if(X) aStart++;
        if(Y) bStart++;

        int ans = 0;
        ans = max(aStart, bStart);
        ans += z;

        return 2 * ans;
    }
};