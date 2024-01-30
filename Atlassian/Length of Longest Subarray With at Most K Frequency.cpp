// Problem Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0, end = 0, ans = 0;
        map<int, int> mp;
        
        while(end < nums.size()) {
            if(mp[nums[end]] < k){
                mp[nums[end]]++;
                end++;
            } else {
                mp[nums[start]]--;
                start++;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
}; 