// Problem Link: https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/

class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(long long x, long long y) {
        long long ans = 1;
        while(y > 0) {    
            if(y & 1) ans = ((ans % mod) * (x % mod)) % mod;
            
            y = y >> 1; 
            x = ((x % mod)* (x) % mod) % mod; 
        }
        return ans;
    }

    int minNonZeroProduct(int p) {
        long long maximumValue = 0;
        maximumValue = (((long long ) 1 ) << p) - 1;
        
        long long secondMaximum = maximumValue - 1;
        secondMaximum = secondMaximum % mod;
        long long c = maximumValue / 2;
        
        secondMaximum = power(secondMaximum, c);
        maximumValue = ((maximumValue % mod) * (secondMaximum % mod) % mod);
        
        return (maximumValue % mod);
    }
};