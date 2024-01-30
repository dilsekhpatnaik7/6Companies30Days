// Problem Link: https://leetcode.com/problems/count-collisions-on-a-road/description/

class Solution {
public:
    int countCollisions(string directions) {
        int left = 0, right = directions.size() - 1;

        while(left < directions.size() && directions[left] == 'L') left++;
        while(right >= 0 && directions[right] == 'R') right--;

        int ans = 0;
        for(int i = left; i <= right; i++) {
            if(directions[i] != 'S') ans++;
        }
        return ans;
    }
};