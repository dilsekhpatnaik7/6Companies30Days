// Problem Link: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = (static_cast<long long>(divisor1) * divisor2) / __gcd(divisor1, divisor2);
        long long total = uniqueCnt1 + uniqueCnt2;
        long long left = total, right = static_cast<long long>(1e12);
        long long ans = 0;

        while(left <= right) {
            long long mid = (left + right) / 2;
            long long both = mid / lcm;

            long long a = mid / divisor2 - both;
            long long b = mid / divisor1 - both;
            total = max(uniqueCnt1 - a, 0ll) + max(uniqueCnt2 - b, 0ll);

            if(mid - a - b >= total + both) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return static_cast<int>(ans);
    }
};