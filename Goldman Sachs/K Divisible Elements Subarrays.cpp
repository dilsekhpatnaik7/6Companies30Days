// Problem Link: https://leetcode.com/problems/k-divisible-elements-subarrays/description/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> s;

        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            string str = "";

            for(int j = i; j < nums.size(); j++) {
                if(nums[j] % p == 0) count++;
                if(count > k) break;

                str += nums[j] + '0';
                s.insert(str);
            }
        }
        return s.size();
    }
};