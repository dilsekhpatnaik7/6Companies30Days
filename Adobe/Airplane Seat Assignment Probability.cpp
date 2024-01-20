// Problem Link: https://leetcode.com/problems/airplane-seat-assignment-probability/description/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1.00;
        return 0.50;
    }
};