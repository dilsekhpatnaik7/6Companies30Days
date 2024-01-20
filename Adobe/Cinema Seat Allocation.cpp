// Problem Link: https://leetcode.com/problems/cinema-seat-allocation/description/

class Solution {
public:
    int solve(int start, int end) {
        if(2 >= start && 9 <= end) return 2;
        else if((2 >= start && 5 <= end) || (6 >= start && 9 <= end) || (4 >= start && 7 <= end)) return 1;
        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = 0;
        sort(reservedSeats.begin(), reservedSeats.end());

        int presentSeat = reservedSeats[0][0];
        int lastSeat = 1;
        set<int> s;
        s.insert(presentSeat);

        for(int i = 0; i < reservedSeats.size(); i++) {
            if(presentSeat == reservedSeats[i][0]) {
                ans += solve(lastSeat, reservedSeats[i][1] - 1);
                lastSeat = reservedSeats[i][1] + 1;
            } else {
                ans += solve(lastSeat, 10);
                ans += solve(1, reservedSeats[i][1] - 1);

                s.insert(reservedSeats[i][0]);
                presentSeat = reservedSeats[i][0];
                lastSeat = reservedSeats[i][1] + 1;
            }
        }

        ans += solve(lastSeat, 10);
        if(s.size() != n) ans += 2 * (n - s.size());

        return ans;
    }
};