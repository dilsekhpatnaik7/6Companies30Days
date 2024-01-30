// Problem Link: https://leetcode.com/problems/maximum-product-after-k-increments/description/

class Solution {
public:
    int mod = 1e9 + 7;

    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k > 0) {
            int ans = pq.top();
            pq.pop();
            ans++;
            pq.push(ans);
            k--;
        }
        long long product = 1;
        while(pq.empty() == false){
            product *= pq.top();
            product = product % mod;
            pq.pop();
        }
        return product;
    }
};