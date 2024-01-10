// Problem Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/

class Solution {
public:
    bool isPalindrome(string& s) {
        int low = 0, high = s.size() - 1;
        while(low < high) {
            if(s[low++] != s[high--]) return false;
        }
        return true;
    }

    void solve(int index, string& s, string& s1, string& s2, int& ans) {
        if(index == s.size()) {
            if(isPalindrome(s1) && isPalindrome(s2)) {
                int currentLength = s1.size() * s2.size();
                ans = max(ans, currentLength);
            }
            return;
        }

        s1.push_back(s[index]);
        solve(index + 1, s, s1, s2, ans);
        s1.pop_back();

        s2.push_back(s[index]);
        solve(index + 1, s, s1, s2, ans);
        s2.pop_back();

        solve(index + 1, s, s1, s2, ans);
    }

    int maxProduct(string s) {
        if(s.size() == 0) return 0;

        int ans = 0;
        string s1 = "", s2 = "";
        solve(0, s, s1, s2, ans);
        
        return ans;
    }
};